/*
   a program to update 2x16 LCD display by LM35 Temp sensor readings
   requirements:
   - connect LCD data path connected to PORTC
   - connect "RS" LCD pin to PD4
   - connect "R/W" LCD pin to PD5
   - connect "E" LCD pin to PD6
   - temprature sensor connected to ADC channel 0
   - this message always exist on LCD: "Temp = x C"
       where x is the temperature value from temp sensor
*/


#include "adc_driver.h"
#include "lcd_driver.h"

int main(void)
{
	uint32_t tempVal;
	LCD_init(); // initialize LCD driver 
	ADC_init(); // initialize ADC driver 
	LCD_clearScreen(); // clear LCD

	LCD_displayString("Temp = ");
	LCD_goToRowColumn(0,11);
	LCD_displayCharacter('C');
    while(1)
    {
		LCD_goToRowColumn(0,7); 
		tempVal = ADC_readChannel(0)/2; 
		LCD_integerToString(tempVal);
    }
}
