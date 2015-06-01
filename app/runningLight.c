#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "runningLight.h"
#include "timingControl.h"
#include "initButton.h"
#include "readButton.h"
#include "defination.h"

void runningLight(State *state, int time){
	static int previousTime = 0 ;

	switch(*state){
		case  INITIAL:	turnOffLED1();
						turnOffLED2();
						turnOffLED3();
						turnOffLED4();
						*state = LED1_ON;
				        break;

		case LED1_ON:	if( waitWithoutDelay( previousTime,time) ){
  	  						previousTime = getCurrentTime();
  	  						turnOnLED1();
  	  						turnOffLED4();
  	  						*state = LED2_ON;
						}
  	  					break;

		case LED2_ON:	if( waitWithoutDelay( previousTime,time) ){
		  	  				previousTime = getCurrentTime();
		  	  				turnOnLED2();
		  	  				turnOffLED1();
		  	  				*state = LED3_ON;
						}
						break;

		case LED3_ON:	if( waitWithoutDelay( previousTime,time) ){
		  	  				previousTime = getCurrentTime();
							turnOnLED3();
							turnOffLED2();
							*state = LED4_ON;
						}
		  	  			break;

		case LED4_ON:	if( waitWithoutDelay( previousTime,time) ){
		  	  				previousTime = getCurrentTime();
		  	  				turnOnLED4();
		  	  				turnOffLED3();
		  	  				*state = LED1_ON;
						}
						break;

		default		:	break;
	}
}


