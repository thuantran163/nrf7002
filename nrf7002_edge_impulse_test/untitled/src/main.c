#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>

/* Logging module (optional, for debug) */
LOG_MODULE_REGISTER(spi_example, LOG_LEVEL_INF);

/* SPI and GPIO configuration */
#define SPI_DEV DT_LABEL(DT_NODELABEL(spi3)) /* SPI3 or your chosen SPI peripheral */
#define CS_GPIO_PORT DT_GPIO_LABEL(DT_NODELABEL(spi3), cs_gpios)
#define CS_GPIO_PIN DT_GPIO_PIN(DT_NODELABEL(spi3), cs_gpios)
#define CS_GPIO_FLAGS DT_GPIO_FLAGS(DT_NODELABEL(spi3), cs_gpios)

/* SPI Configuration */
static const struct spi_cs_control spi_cs = {
    .gpio = GPIO_DT_SPEC_GET(DT_NODELABEL(spi3), cs_gpios),
    .delay = 0,
};

static const struct spi_config spi_cfg = {
    .frequency = 1000000, /* 1 MHz */
    .operation = SPI_WORD_SET(8) | SPI_TRANSFER_MSB | SPI_OP_MODE_MASTER,
    .slave = 0,
    .cs = &spi_cs,
};

/* SPI device */
const struct device *spi_dev;

/* Initialize SPI and CS GPIO */
void spi_init(void)
{
    /* Get SPI device */
    spi_dev = DEVICE_DT_GET(DT_NODELABEL(spi3));
    if (!device_is_ready(spi_dev)) {
        LOG_ERR("SPI device not ready");
        return;
    }

    /* Configure CS GPIO */
    const struct gpio_dt_spec cs_spec = GPIO_DT_SPEC_GET(DT_NODELABEL(spi3), cs_gpios);
    if (!device_is_ready(cs_spec.port)) {
        LOG_ERR("CS GPIO device not ready");
        return;
    }

    gpio_pin_configure(cs_spec.port, cs_spec.pin, GPIO_OUTPUT_INACTIVE | cs_spec.dt_flags);

    LOG_INF("SPI initialized with CS active low");
}

/* Perform SPI transfer */
void spi_transfer(void)
{
    uint8_t tx_data[] = {0xAA, 0xBB, 0xCC}; /* Data to send */
    uint8_t rx_data[sizeof(tx_data)] = {0};

    const struct spi_buf tx_buf = {
        .buf = tx_data,
        .len = sizeof(tx_data),
    };
    const struct spi_buf rx_buf = {
        .buf = rx_data,
        .len = sizeof(rx_data),
    };

    const struct spi_buf_set tx = {
        .buffers = &tx_buf,
        .count = 1,
    };
    const struct spi_buf_set rx = {
        .buffers = &rx_buf,
        .count = 1,
    };

    if (spi_transceive(spi_dev, &spi_cfg, &tx, &rx) == 0) {
        LOG_INF("SPI Transfer successful");
        LOG_HEXDUMP_INF(rx_data, sizeof(rx_data), "Received Data");
    } else {
        LOG_ERR("SPI Transfer failed");
    }
}

void main(void)
{
    /* Initialize SPI */
    spi_init();

    /* Perform a transfer */
    while (1) {
        spi_transfer();
        k_sleep(K_MSEC(1000)); /* Delay 1 second */
    }
}
