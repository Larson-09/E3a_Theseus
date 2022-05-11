/**
  ******************************************************************************
  * @file    main.c
  * @author  Nirgal
  * @date    03-July-2019
  * @brief   Default main function.
  ******************************************************************************
*/

// Global includes
#include "stm32f1xx_hal.h"
#include "stm32f1_uart.h"
#include "stm32f1_sys.h"
#include "stm32f1_gpio.h"
#include "macro_types.h"
#include "systick.h"

// Libraries includes
#include "secretary.h"
#include "engineManagement.h"
#include "usSensor.h"
#include "colorSensor.h"

// Type definitions
typedef enum {
	STANDBY,
	FORWARD,
	FIND_WAY,
	TURN,
	SIGNAL_OBSTACLE
} System_State;

// Static methods prototype
static void testComponents(void);
static void stateMachine();

int main(void)
{
	//Initialisation de la couche logicielle HAL (Hardware Abstraction Layer)
	//Cette ligne doit rester la première étape de la fonction main().
	HAL_Init();


	//Initialisation de l'UART2 à la vitesse de 115200 bauds/secondes (92kbits/s) PA2 : Tx  | PA3 : Rx.
		//Attention, les pins PA2 et PA3 ne sont pas reliées jusqu'au connecteur de la Nucleo.
		//Ces broches sont redirigées vers la sonde de débogage, la liaison UART étant ensuite encapsulée sur l'USB vers le PC de développement.
	UART_init(UART2_ID,115200);

	//"Indique que les printf sortent vers le périphérique UART2."
	SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

	//Initialisation du port de la led Verte (carte Nucleo)
	BSP_GPIO_PinCfg(LED_GREEN_GPIO, LED_GREEN_PIN, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);

	//Initialisation du port du bouton bleu (carte Nucleo)
	BSP_GPIO_PinCfg(BLUE_BUTTON_GPIO, BLUE_BUTTON_PIN, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);


	// Main function
	testComponents();
}

static void testComponents(void){
	SECRETARY_process_main();
	char* rgbCode = COLOR_SENSOR_testColorSensor();
	printf(rgbCode);
}

//static void stateMachine(){
//
//	System_State system_state;
//	Direction nextDirection = FORWARD;
//	Direction itinerary[128];
//	unint16_t directionIndex = 0;
//
//	// Main loop
//	while(1)
//	{
//		switch(system_state){
//
//			case STANDBY:
//				// If the user press the button on the car
//				if(1){
//					// Then, enter the FORWARD mode
//					system_state = FORWARD;
//				}
//				break;
//
//
//			case FORWARD:
//				// Make the car go forward
//				goForward();
//
//				// If the car meet a cross line
//				if(meetCrossLine()){
//					// Then, enter the FIND_WAY mode
//					system_state = FIND_WAY;
//				}
//				// Else, if the car meet an obstacle
//				else if(meetObstacle()){
//					// Then, enter the FIND_WAY mode
//					system_state = SIGNAL_OBSTACLE;
//				}
//
//				break;
//
//			case FIND_WAY:
//				// Stop the car
//				stopCar();
//
//				// Get the next instruction
//				nextDirection = itinerary[directionIndex];
//
//				// Update itinerary
//				directionIndex ++;
//
//				// Enter the adapted mode
//				if(nextDirection != FORWARD){
//					system_state = TURN;
//				}
//				else{
//					system_state = FORWARD;
//				}
//
//				break;
//
//			case TURN:
//				// Turn right
//				turn(nextDirection);
//
//				// Go back in FORWARD mode
//				system_state = FORWARD;
//				break;
//
//			case SIGNAL_OBSTACLE:
//
//				// Signal the obstacle
//				US_SENSOR_signalObstacle(directionIndex);
//
//				// Compute new itinerary
//				itinerary= US_SENSOR_computeNewItinerary(itinerary, instructionIndex);
//				break;
//		}
//
//
//	}
//}
