#ifndef US_SENSOR_H
#define US_SENSOR_H

// Includes
#include "HC-SR04/HCSR04.h"

// Prototypes
void US_SENSOR_test(void);
void US_SENSOR_signalObstacle(int16_t instructionIndex);
//Direction* US_SENSOR_computeNewItinerary(Direction* initialItinerary,int instructionIndexWithObstacle);


#endif /*US_SENSOR_H*/
