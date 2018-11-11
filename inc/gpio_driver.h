/**
  *
  * @file    gpio_driver.h
  * @author  ProfHindsight
  * @version x
  * @date    11/10/2018
  * @brief   This is a gpio driver. It's mostly GPIO mapping. A hardware configuration file needs to be made for the custom board.
  */

// The STM32F030K6T6 has 26 I/O
#include "stm32f0xx.h"
#include "stm32f0xx_gpio.h"

typedef enum gpio_pins
{
	gpio_i2c_scl 		= 0,
	gpio_i2c_sda 		= 1,
	gpio_i2c_power 		= 2,
	gpio_nrf24_miso 	= 3,
	gpio_nrf24_mosi 	= 4,
	gpio_nrf24_clk 		= 5,
	gpio_nrf24_cs 		= 6,
	gpio_nrf24_ce		= 7,
	gpio_nrf24_power 	= 8,
	gpio_nrf24_pa_en 	= 9,
	gpio_bat_detect 	= 10,
	gpio_debug_rx 		= 11,
	gpio_debug_tx 		= 12,
	gpio_clk_lfxo1 		= 13,
	gpio_clk_lfxo2 		= 14,
	gpio_swclk			= 15,
	gpio_swdio			= 16,
	gpio_nrst			= 17,
	gpio_swo 			= 18
}gpio_pins_t;

typedef struct gpio_struct
{
	uint32_t gpio_port;
	uint16_t gpio_pin;
}

const gpio_struct gpio_pin_mapping[] = {
	{GPIOB, GPIO_Pin_8} // gpio_i2c_scl		- D15
	{GPIOB, GPIO_Pin_9} // gpio_i2c_sda		- D14
	{GPIOA, GPIO_Pin_9} // gpio_i2c_power 	- D8
	{GPIOA, GPIO_Pin_6} // gpio_nrf24_miso	- D12
	{GPIOA, GPIO_Pin_7} // gpio_nrf24_mosi	- D11
	{GPIOA, GPIO_Pin_5} // gpio_nrf24_clk	- D13
	{GPIOB, GPIO_Pin_6} // gpio_nrf24_cs	- D10
	{GPIOC, GPIO_Pin_7} // gpio_nrf24_ce 	- D9
	{GPIOA, GPIO_Pin_8} // gpio_nrf24_power - D7
	{GPIOB, GPIO_Pin_10}// gpio_nrf24_pa_en - D6
	{GPIOA, GPIO_Pin_0} // gpio_bat_detect 	- A0
	{GPIOA, GPIO_Pin_3} // gpio_debug_rx	- D0
	{GPIOA, GPIO_Pin_2} // gpio_debug_tx	- D1
	{} // gpio_clk_lfxo1 					TODO: Define These
	{} // gpio_clk_lfxo2
	{} // gpio_swclk
	{} // gpio_swdio
	{} // gpio_nrst
	{} // gpio_swo
}

const GPIOMode_TypeDef gpio_pin_direction[] = 
{
	GPIO_MODE_AF 	// gpio_i2c_scl		- D15
	GPIO_MODE_AF 	// gpio_i2c_sda		- D14
	GPIO_MODE_OUT 	// gpio_i2c_power 	- D8
	GPIO_MODE_AF 	// gpio_nrf24_miso	- D12
	GPIO_MODE_AF 	// gpio_nrf24_mosi	- D11
	GPIO_MODE_AF 	// gpio_nrf24_clk	- D13
	GPIO_MODE_AF 	// gpio_nrf24_cs	- D10
	GPIO_MODE_AF 	// gpio_nrf24_ce 	- D9
	GPIO_MODE_OUT	// gpio_nrf24_power - D7
	GPIO_MODE_OUT	// gpio_nrf24_pa_en - D6
	GPIO_MODE_AN	// gpio_bat_detect 	- A0
	GPIO_MODE_AF 	// gpio_debug_rx	- D0
	GPIO_MODE_AF 	// gpio_debug_tx	- D1
	// gpio_clk_lfxo1 	TODO: Define These
	// gpio_clk_lfxo2
	// gpio_swclk
	// gpio_swdio
	// gpio_nrst
	// gpio_swo
}

const uint8_t gpio_af_selection[] = 
{
	GPIO_MODE_AF 	// gpio_i2c_scl		- D15
	GPIO_MODE_AF 	// gpio_i2c_sda		- D14
	GPIO_AF_0 	// gpio_i2c_power 	- D8
	GPIO_MODE_AF 	// gpio_nrf24_miso	- D12
	GPIO_MODE_AF 	// gpio_nrf24_mosi	- D11
	GPIO_MODE_AF 	// gpio_nrf24_clk	- D13
	GPIO_MODE_AF 	// gpio_nrf24_cs	- D10
	GPIO_MODE_AF 	// gpio_nrf24_ce 	- D9
	GPIO_AF_0	// gpio_nrf24_power - D7
	GPIO_AF_0	// gpio_nrf24_pa_en - D6
	GPIO_AF_0	// gpio_bat_detect 	- A0
	GPIO_MODE_AF 	// gpio_debug_rx	- D0
	GPIO_MODE_AF 	// gpio_debug_tx	- D1
	// gpio_clk_lfxo1 	TODO: Define These
	// gpio_clk_lfxo2
	// gpio_swclk
	// gpio_swdio
	// gpio_nrst
	// gpio_swo
}


void initialize_gpio(void);
void write_gpio(gpio_pins_t gpio_pin, uint8_t value);
uint8_t read_gpio(gpio_pins_t gpio_pin);
uint16_t read_analog_gpio(gpio_pins_t gpio_adc_pin);
float read_analog_voltage(gpio_pins_t gpio_adc_pin);
