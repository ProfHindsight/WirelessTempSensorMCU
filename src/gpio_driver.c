/**
  *
  * @file    gpio_driver.c
  * @author  ProfHindsight
  * @version x
  * @date    11/11/2018
  * @brief   This is a gpio driver. It's mostly GPIO mapping. A hardware configuration file needs to be made for the custom board.
  */
#include "gpio_driver.h"


void initialize_gpio(void)
{

}
void write_gpio(gpio_pins_t gpio_pin, uint8_t value)
{

}
uint8_t read_gpio(gpio_pins_t gpio_pin)
{
	return 0;
}
uint16_t read_analog_gpio(gpio_pins_t gpio_adc_pin)
{
	return 0;
}
float read_analog_voltage(gpio_pins_t gpio_adc_pin)
{
	return 0;
}
