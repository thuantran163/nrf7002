/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

/* STEP 1.2 - Include the header files for SPI, GPIO and devicetree */
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include "LIS302DL.h"
LOG_MODULE_REGISTER(Lesson5_Exercise1, LOG_LEVEL_INF);

const struct gpio_dt_spec ledspec = GPIO_DT_SPEC_GET(DT_NODELABEL(led0), gpios);

/* STEP 3 - Retrieve the API-device structure */
// #define SPIOP	SPI_WORD_SET(8) | SPI_TRANSFER_MSB
// struct spi_dt_spec spispec = SPI_DT_SPEC_GET(DT_NODELABEL(bme280), SPIOP, 0);

/* Data structure to store BME280 data */

int main(void)
{
	int err;
	
	err = gpio_is_ready_dt(&ledspec);
	if (!err) {
		LOG_ERR("Error: GPIO device is not ready, err: %d", err);
		return 0;
	}

	/* STEP 10.1 - Check if SPI and GPIO devices are ready */
	// err = spi_is_ready_dt(&spispec);
	if (!err) {
		LOG_ERR("Error: SPI device is not ready, err: %d", err);
		return 0;
	}

	gpio_pin_configure_dt(&ledspec, GPIO_OUTPUT_ACTIVE);
	
	/* STEP 10.2 - Read calibration data */

	/* STEP 10.3 - Write sampling parameters and read and print the registers */
	// bme_write_reg(CTRLHUM, 0x04);
	// bme_write_reg(CTRLMEAS, 0x93);	
	
	LOG_INF("Continuously read sensor samples, compensate, and display");

	while(1){
		hello_world();
		/* STEP 10.4 - Continuously read sensor samples and toggle led */
		// bme_read_sample();
		gpio_pin_toggle_dt(&ledspec);
		k_msleep(1);
	}

	return 0;
}
