#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "initLED.h"
#include "initButton.h"
#include "defination.h"
#include "runningLight.h"
#include "timingControl.h"

int main(void){
	State  state4 = INITIAL;

	initLED();
	initButton();

    while(1){

    	runningLight(&state4, ONE_HUNDRED_MILI_SEC);
    }
}


