#include "usSensor.h";
#include "stm32f1_gpio.h"
#define HCSR04_NB_SENSORS 1

void US_SENSOR_test(){
	HCSR04_add(1,GPIO_PIN_5,5,GPIO_PIN_4,4);
	HCSR04_demo_state_machine();
}
