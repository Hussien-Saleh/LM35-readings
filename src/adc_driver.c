#include "adc_driver.h"

void ADC_init(void)
{
    ADMUX &= ~(0xFF); // initialize ADC Channel 0, AREF, internal Vref off, right adjusted
	ADCSRA |= (1<<ADEN); // enable ADC module
	ADCSRA |= (0x03<<ADPS0); // ADPS2:0 = 011 , ADC CLK = CPU_CLK (1Mhz)/8 = 125khz
}

uint16_t ADC_readChannel(uint8_t channel)
{
	ADMUX &= ~(0x1F<<MUX0); // clear MUX4:0 bits before setting the required channel
	ADMUX = ADMUX | (channel & 0x07); // setting the channel in ADMUX 
	
	ADCSRA |= (1<<ADSC); // start conversion
	while (!(ADCSRA & (1<<ADSC)));
	return ADC; 
}
