#ifndef US_SENSOR_H
#define US_SENSOR_H

// Includes
#include "HCSR04.h"

// Prototypes
void US_SENSOR_test(void);
void US_SENSOR_signalObstacle(int16_t instructionIndex);
system_state* US_SENSOR_computeNewItinerary(System_State* initialItinerary, instructionIndexWithObstacle);


#endif /*US_SENSOR_H*/
