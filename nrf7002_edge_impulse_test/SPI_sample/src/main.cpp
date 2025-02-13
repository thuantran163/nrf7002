#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/sensor.h>
#include "LIS302DL.h"

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <sstream>

#include "edge-impulse-sdk/classifier/ei_run_classifier.h"

int detect_motion(std::vector<float>& raw_features);




static int64_t sampling_freq = EI_CLASSIFIER_FREQUENCY; // in Hz.
static int64_t time_between_samples_us = (1000000 / (sampling_freq - 1));



// Callback function declaration
static int get_signal_data(size_t offset, size_t length, float *out_ptr);

void *__dso_handle = 0;

LOG_MODULE_REGISTER(Lesson5_Exercise1, LOG_LEVEL_INF);

const struct gpio_dt_spec ledspec = GPIO_DT_SPEC_GET(DT_NODELABEL(led0), gpios);
void convert_to_sensor_value(const OutValue_TypeDef *out_val, struct sensor_value *sensor_val) {
    sensor_val[0].val1 = (int32_t) out_val->OUT_X;
    sensor_val[0].val2 = 0;  // No fractional part

    sensor_val[1].val1 = (int32_t) out_val->OUT_Y;
    sensor_val[1].val2 = 0;

    sensor_val[2].val1 = (int32_t) out_val->OUT_Z;
    sensor_val[2].val2 = 0;
}

int main(void)
{
	int err;
	
	err = gpio_is_ready_dt(&ledspec);
	if (!err) {
		LOG_ERR("Error: GPIO device is not ready, err: %d", err);
		return 0;
	}

	if (!err) {
		LOG_ERR("Error: SPI device is not ready, err: %d", err);
		return 0;
	}

	gpio_pin_configure_dt(&ledspec, GPIO_OUTPUT_ACTIVE);

	
	LOG_INF("Continuously read sensor samples, compensate, and display");
	while(1){
    std::vector<float> features;

    for (size_t ix = 0; ix < EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE;
                          ix += EI_CLASSIFIER_RAW_SAMPLES_PER_FRAME) {
      // start a timer that expires when we need to grab the next value
      struct k_timer next_val_timer;
      k_timer_init(&next_val_timer, NULL, NULL);
      k_timer_start(&next_val_timer, K_USEC(time_between_samples_us), K_NO_WAIT);
      OutValue_TypeDef value_accelerometer = read_accelerometerData();
      // fill the features array
      struct sensor_value sensor_data[3];
      convert_to_sensor_value(&value_accelerometer, sensor_data); 
      
      features[ix + 0] = sensor_value_to_double(&sensor_data[0]);
      features[ix + 1] = sensor_value_to_double(&sensor_data[1]);
      features[ix + 2] = sensor_value_to_double(&sensor_data[2]);

      // busy loop until next value should be grabbed
      while (k_timer_status_get(&next_val_timer) <= 0);
      
    }
    
    detect_motion(features);


	}

	return 0;
}
// Trim whitespace around value




int detect_motion(std::vector<float>& raw_features) {


    // Make sure that the length of the buffer matches expected input length
    if (raw_features.size() != EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
        printk("The size of your 'features' array is not correct. Expected %d items, but had %lu\n",
            EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, raw_features.size());
        return 1;
    }

    // Stores the prediction results from inference
    ei_impulse_result_t result;

    // Set up callback for providing raw features to run_classifier()
    signal_t signal;
    numpy::signal_from_buffer(&raw_features[0], raw_features.size(), &signal);

    // Perform DSP pre-processing and inference
    EI_IMPULSE_ERROR res = run_classifier(&signal, &result, false);

    // Print return code and how long it took to perform inference
    printk("run_classifier returned: %d\r\n", res);
    printk("Timing: DSP %d ms, inference %d ms, anomaly %d ms\r\n", 
            result.timing.dsp, 
            result.timing.classification, 
            result.timing.anomaly);
    printk("Begin output\r\n");

    // Print the prediction results (object detection)
#if EI_CLASSIFIER_OBJECT_DETECTION == 1
    printk("Object detection bounding boxes:\r\n");
    for (uint32_t i = 0; i < result.bounding_boxes_count; i++) {
        ei_impulse_result_bounding_box_t bb = result.bounding_boxes[i];
        if (bb.value == 0) {
            continue;
        }
        printk("  %s (%f) [ x: %u, y: %u, width: %u, height: %u ]\r\n", 
                bb.label, 
                bb.value, 
                bb.x, 
                bb.y, 
                bb.width, 
                bb.height);
    }

    // Print the prediction results (classification)
#else
    printk("Predictions:\r\n");
    for (uint16_t i = 0; i < EI_CLASSIFIER_LABEL_COUNT; i++) {
        printk("  %s: ", ei_classifier_inferencing_categories[i]);
        printk("%.5f\r\n", result.classification[i].value);
    }
#endif

    // Print anomaly result (if it exists)
#if EI_CLASSIFIER_HAS_ANOMALY == 1
    printk("Anomaly prediction: %.3f\r\n", result.anomaly);
#endif

    printk("End output\r\n");

    return 0;
}
