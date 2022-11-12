#ifndef MAX6675_H_
#define MAX6675_H_

#include "stdlib.h"
#include "stdbool.h"
#include "stm32f7xx_hal.h"

extern SPI_HandleTypeDef hspi1;
//#define SPI_TYPEDEF hspi1;

#define HIGH_TEMP_C 1024 // maximum temperature reading +1024 celcius
#define DATA_OUTPUT_RES 4096 // 12 bit resolution output

typedef struct max6675_tc max6675_tc;

struct max6675_tc {
    float tempCelcius;
    GPIO_TypeDef* CS_PORT;
    uint16_t CS_PIN;
};

max6675_tc* tc_init(GPIO_TypeDef* CS_PORT, uint16_t CS_PIN);
float tc_readTemp(max6675_tc* sensor);
void tc_clean(max6675_tc* sensor);


#endif