#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#include <zephyr/device.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>

//#define SPI_CS_PIN     25 // Chip Select pin (adjust based on your setup)
//#define SPI_CS_PORT    DT_LABEL(DT_NODELABEL(gpio0))  // Adjust based on your GPIO port
//#define SPI_FREQ       500000 // SPI frequency in Hz (adjust as needed)
//
//// SPI Device configuration
//extern const struct device *spi_dev;
//extern struct spi_config spi_cfg;
//
//int spi_init(void);
//int spi_transmit(const uint8_t *tx_buf, uint8_t *rx_buf, size_t len);

#endif /* SPI_DRIVER_H_ */