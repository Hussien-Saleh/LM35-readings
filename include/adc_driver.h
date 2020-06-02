#ifndef _ADC_DRIVER_H_
#define _ADC_DRIVER_H_

#include "mcu.h"
#include <stdint.h>

/*
 *  Initialize ADC driver.
 */

void ADC_init(void);

/*
 * Read analog data from an ADC channel and convert into digital representation
 */

uint16_t ADC_readChannel(uint8_t channel);

#endif 
