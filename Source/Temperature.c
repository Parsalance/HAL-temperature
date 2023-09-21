#include "Temperature.h"


Temp newTemp(){
	Temp new_Temp;
	new_Temp.temperatureWidth = 16;
	new_Temp.defaultTemperatureResolution = 9;
	new_Temp.defaultTemperatureFracWidth = 8;
	new_Temp.maxTemperatureResolution = 9;
	new_Temp.address = 0x48;
	return new_Temp;
}


int tempCheck(Temp* _Temp){
	uint8_t buf[1];
	buf[0] = 0x00;
	uint8_t address = _Temp->address << 1;
	HAL_StatusTypeDef ret;
	ret = HAL_I2C_Master_Transmit(_Temp->hI2Cx, address, buf, 1, HAL_MAX_DELAY);
      if ( ret != HAL_OK ) {
          return 404;
      }else{
          return 200;
      }
}


int getTemperature(Temp* _Temp){
	int16_t val;
	uint8_t buf[2];
	buf[0] = 0x00;
	uint8_t address = _Temp->address << 1;
	HAL_I2C_Master_Receive(_Temp->hI2Cx, address, buf, 2, HAL_MAX_DELAY);
    val = (((int16_t)buf[0] << 8) | (buf[1])) >> 7;
    int temperature = val * 0.5;
	return temperature;
}


