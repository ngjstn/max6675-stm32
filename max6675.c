#include "max6675.h" 


max6675_tc* tc_create(void) {
    return (max6675_tc*)malloc(sizeof(max6675_tc)); 
}


float tc_readTemp(max6675_tc* sensor, GPIO_TypeDef* CS_PORT, uint16_t CS_PIN) {
    uint8_t buffer[2]; 
    uint16_t rawTempValue; 

    HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET); 
    HAL_SPI_Receive(&SPI_TYPEDEF, buffer, 1, HAL_MAX_DELAY); 
    HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET); 

    rawValue = (buffer[0] | (buffer[1] << 8)) >> 3; 
    sensor->rawTemp = rawValue; 

    float celcius = rawValue * HIGH_TEMP_C / DATA_OUTPUT_RES; 
    sensor->tempCelcius = celcius; 

    return celcius; 
}


void tc_free(max6675* sensor) {
    free(sensor); 
}