#include "Accelero_instance.h"
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>


/* STEP 3 - Retrieve the API-device structure */
#define SPIOP	SPI_WORD_SET(8) | SPI_TRANSFER_MSB
struct spi_dt_spec spispec = SPI_DT_SPEC_GET(DT_NODELABEL(bme280), SPIOP, 0);
#define CS_PIN 			DT_GPIO_PIN(DT_NODELABEL(spi1), cs_gpios)
#define CS_FLAGS		DT_GPIO_FLAGS(DT_NODELABEL(spi1), cs_gpios)
//#define CS_GPIO_PIN 16
#define SPI_DEV "SPI_1"
#define GPIO_PORT_LABEL "GPIO_0"
#define GPIO_PIN        25


static const struct spi_config spi_cfg ={
  .frequency = 1000000,
  .operation = SPI_OP_MODE_MASTER | SPI_TRANSFER_MSB | SPI_WORD_SET(8),
  .cs = CS_PIN,
//  .max_freq = 1000000
};
//static const struct device *spi_dev =device_get_binding(spispec.bus->label);
static const  struct device *gpio_dev; 
void toggle_cs_gpio(bool assert) 
{
  gpio_dev = device_get_binding("GPIO_0");
  gpio_pin_configure(gpio_dev, GPIO_PIN, GPIO_OUTPUT );
  gpio_pin_set(gpio_dev, GPIO_PIN, assert ? 0 :1);

}
//const struct device *cs_gpio;

int ACCELERO_IO_Read(uint8_t reg, uint8_t *data, uint8_t size)
{
  //spi_dev = device_get_binding(SPI_DEV);

//  toggle_cs_gpio(true);
	//cs_gpio = device_get_biding(DT_LABEL(DT_NODELABEL(gpio0)));
//const  struct device *cs_gpio;
//  cs_gpio = device_get_binding("GPIO_0");
//  gpio_pin_configure(cs_gpio,CS_PIN, GPIO_OUTPUT_ACTIVE | CS_FLAGS);
//	gpio_pin_set(cs_gpio, CS_PIN, 0);
	k_msleep(1);
	int err;

	/* STEP 4.1 - Set the transmit and receive buffers */
	uint8_t tx_buffer = reg;
	struct spi_buf tx_spi_buf			= {.buf = (void *)&tx_buffer, .len = 1};
	struct spi_buf_set tx_spi_buf_set 	= {.buffers = &tx_spi_buf, .count = 2};
	struct spi_buf rx_spi_bufs 			= {.buf = data, .len = size};
	struct spi_buf_set rx_spi_buf_set	= {.buffers = &rx_spi_bufs, .count = 2};

	
  /* STEP 4.2 - Call the transceive function */
  //err = spi_transceive(spi_dev, &spi_cfg, &tx_spi_buf_set, &rx_spi_buf_set);
	err = spi_transceive_dt(&spispec, &tx_spi_buf_set, &rx_spi_buf_set);
	if (err < 0) {
		// LOG_ERR("spi_transceive_dt() failed, err: %d", err);
		return err;
	}
//  toggle_cs_gpio(false);
//	gpio_pin_set(cs_gpio, CS_PIN, 1);
	k_msleep(1);

	return 0;
}
int ACCELERO_IO_Write(uint8_t reg, uint8_t value)
{
//  struct device *cs_gpio;
//  cs_gpio = device_get_binding("GPIO_0");
//  gpio_pin_configure(cs_gpio,CS_PIN, GPIO_OUTPUT_ACTIVE | CS_FLAGS);
//	cs_gpio = device_get_binding("GPIO_0");
//	gpio_pin_configure(cs_gpio,CS_PIN, GPIO_OUTPUT_ACTIVE | CS_FLAGS);
//	gpio_pin_set(cs_gpio, CS_PIN, 0);
//	k_msleep(1);
	int err;

	/* STEP 5.1 - declare a tx buffer having register address and data */
	//uint8_t tx_buf[] = {(reg & 0x7F), value};	
	uint8_t tx_buf[] = {reg , value};	
	struct spi_buf 		tx_spi_buf 		= {.buf = tx_buf, .len = sizeof(tx_buf)};
	struct spi_buf_set 	tx_spi_buf_set	= {.buffers = &tx_spi_buf, .count = 2};

	/* STEP 5.2 - call the spi_write_dt function with SPISPEC to write buffers */
	err = spi_write_dt(&spispec, &tx_spi_buf_set);
	if (err < 0) {
		// LOG_ERR("spi_write_dt() failed, err %d", err);
		return err;
	}

//	gpio_pin_set(cs_gpio, CS_PIN, 1);
	k_msleep(1);

	return 0;
}
