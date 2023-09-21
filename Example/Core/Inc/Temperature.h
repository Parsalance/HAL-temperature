#include "main.h"

#define temperatureReg 0x00
#define configurationReg 0x01
#define temperatureLowReg 0x02
#define temperatureHighReg 0x03

#define SensorFounded 200
#define SensorNotFound 404

typedef struct TemperatureSetting{
	
	// Hardware setings:
	I2C_HandleTypeDef* hI2Cx;
	
	// Module settings:
	int				temperatureWidth;
	int 			defaultTemperatureResolution;
	int			    defaultTemperatureFracWidth;
	int			    maxTemperatureResolution;
	uint8_t         address;
} Temp;

Temp newTemp(void);
int tempCheck(Temp* _Temp);
int getTemperature(Temp* _Temp);

