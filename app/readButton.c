#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "readButton.h"
#include "initButton.h"
#include "defination.h"

int buttonIsNotPressed(){

	GPIO_PinState readButton ;
	readButton = buttonPressed();

	if(readButton == 0 )
		return 1;
	return 0;
}

int buttonIsPressed(){

	GPIO_PinState readButton ;
	readButton = buttonPressed();

	if(readButton == 1 )
		return 1;
	return 0;
}
