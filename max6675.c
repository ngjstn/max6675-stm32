#include "max6675.h"

max6675_tc* tc_init(GPIO_TypeDef* CS_PORT, uint16_t CS_PIN) {
    max6675_tc* sensor = (max6675_tc*)malloc(sizeof(max6675_tc));
    sensor->CS_PORT = CS_PORT;
    sensor->CS_PIN = CS_PIN;
    return sensor;
}

float tc_readTemp(max6675_tc* sensor) {
    uint8_t buffer[2];
    uint16_t rawValue;

    HAL_GPIO_WritePin(sensor->CS_PORT, sensor->CS_PIN, GPIO_PIN_RESET);
    HAL_SPI_Receive(&hspi1, buffer, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(sensor->CS_PORT, sensor->CS_PIN, GPIO_PIN_SET);

    rawValue = (buffer[0] | (buffer[1] << 8)) >> 3;
    float celcius = rawValue * HIGH_TEMP_C / DATA_OUTPUT_RES;
    sensor->tempCelcius = celcius;

    return celcius;
}

void tc_free(max6675_tc* sensor) {
    free(sensor);
}