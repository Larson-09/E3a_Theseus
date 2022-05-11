#include "colorSensor.h"

// static methods prototypes


/*
 * This method initialize the APDS9960 and display the color (RGB format)
 */
char* COLOR_SENSOR_testColorSensor(void){
	APDS9960_init();
	APDS9960_enableLightSensor(FALSE);
	//APDS9960_setLEDDrive(1);
	while(1)
	{
		uint16_t ambiant, red, blue, green;
		APDS9960_readAmbientLight(&ambiant);
		APDS9960_readRedLight(&red);
		APDS9960_readBlueLight(&blue);
		APDS9960_readGreenLight(&green);

		if(ambiant)
		{
			blue = (uint16_t)(((uint32_t)blue*100)/ambiant);
			red = (uint16_t)(((uint32_t)red*100)/ambiant);
			green = (uint16_t)(((uint32_t)green*100)/ambiant);
		}

		char* rgbCode = "";
		sprintf(rgbCode, "A:%d\tR:%d\tG:%d\tB:%d\n",ambiant, red, green, blue);
		HAL_Delay(500);

		return rgbCode;
	}
}
