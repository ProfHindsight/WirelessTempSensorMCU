#include "stm32f0xx_conf.h"

void SysTick_Handler(void) {
  static uint16_t tick = 0;

  switch (tick++) {
  	case 100:
  		tick = 0;
  		GPIOA->ODR ^= (1 << 5);
  		break;
  }
}

int main(void)
{

	RCC->AHBENR |= RCC_AHBENR_GPIOAEN; 	// enable the clock to GPIOA
						//(RM0091 lists this as IOPCEN, not GPIOCEN)

	GPIOA->MODER = (1 << 10); // Setting "01" to bits 18 and 19 for Push Pull

	SysTick_Config(SystemCoreClock/100);

	while(1);

}
