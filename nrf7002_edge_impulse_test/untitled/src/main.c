#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
/* STEP 1.2 - Include the header files for SPI, GPIO and devicetree */
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/util.h>

#define SPI_DEVICE_NODE DT_NODELABEL(my_spi_device)
#define SPI_DEV_NAME DT_LABEL(SPI_DEVICE_NODE)

static const struct device *spi_dev;
static const struct device *gpio_dev;
static struct spi_config spi_cfg;
static const struct gpio_dt_spec cs_gpio = GPIO_DT_SPEC_GET(SPI_DEVICE_NODE, cs_gpios);

// Initialize SPI device and configure CS GPIO pin
static int spi_init(void)
{
    // Get the SPI device binding
    spi_dev = device_get_binding(SPI_DEV_NAME);
    if (!spi_dev) {
        printk("Error: Failed to get SPI device\n");
        return -ENODEV;
    }

    // Get the GPIO device binding
    gpio_dev = device_get_binding(DT_LABEL(DT_NODELABEL(gpio0)));
    if (!gpio_dev) {
        printk("Error: Failed to get GPIO device\n");
        return -ENODEV;
    }

    // Configure CS pin as output (active-high by default)
    int ret = gpio_pin_configure_dt(&cs_gpio, GPIO_OUTPUT_ACTIVE);
    if (ret) {
        printk("Error: Failed to configure CS GPIO pin\n");
        return ret;
    }

    // SPI configuration (CPOL = 0, CPHA = 0, MSB first)
    spi_cfg.frequency = 1000000;  // 1 MHz
    spi_cfg.operation = SPI_OP_MODE_MASTER | SPI_WORD_SET(8) | SPI_TRANSFER_MSB;
    spi_cfg.slave = 0;  // Master mode

    return 0;
}

// SPI transmission function (with active-low CS)
static int spi_transmit(uint8_t *tx_buf, size_t len)
{
    struct spi_buf tx_bufs[] = {
        {
            .buf = tx_buf,
            .len = len
        }
    };

    struct spi_buf_set tx = {
        .buffers = tx_bufs,
        .count = ARRAY_SIZE(tx_bufs)
    };

    // Activate CS (CS is active-low, so set to low to select the device)
    gpio_pin_set_dt(&cs_gpio, 0);  // CS low

    // Perform the SPI transfer
    int ret = spi_transceive(spi_dev, &spi_cfg, &tx, NULL);
    if (ret) {
        printk("SPI transfer failed\n");
    }

    // Deactivate CS (CS is active-low, so set to high to deselect the device)
    gpio_pin_set_dt(&cs_gpio, 1);  // CS high

    return ret;
}

void main(void)
{
    int ret = spi_init();
    if (ret) {
        printk("SPI initialization failed\n");
        return;
    }

    uint8_t tx_data[] = {0x01, 0x02, 0x03};  // Example data to transmit

    ret = spi_transmit(tx_data, sizeof(tx_data));
    if (ret) {
        printk("SPI transmission failed\n");
    } else {
        printk("SPI transmission successful\n");
    }
}
