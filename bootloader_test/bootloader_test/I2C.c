/*
 * I2C.c
 *
 * Created: 16/01/2018 12:16:48 PM
 *  Author: Zakaria Gomaa
 */ 

#ifndef  F_CPU
#define F_CPU 16000000UL
#endif


#include <util/twi.h>

#include "I2C.h"

#define F_SCL 100000UL // SCL frequency



#include <util/twi.h>
#define F_SCL 100000UL // SCL frequency
#define Prescaler 1
#define TWBR_val ((((F_CPU / F_SCL) / Prescaler) - 16 ) / 2)

void I2C_Init(void)
{
	TWBR = (uint8_t)TWBR_val;
}


void I2C_start(void)
{
	// reset TWI control register
	TWCR = 0;
	// transmit START condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );

}
void I2C_stop(void)
{
	// transmit STOP condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	while ((TWCR & (1<<TWSTO)));
}
void I2C_write(uint8_t data)
{
// load data into data register
TWDR = data;
// start transmission of data
TWCR = (1<<TWINT) | (1<<TWEN);
// wait for end of transmission
while( !(TWCR & (1<<TWINT)) );
}
uint8_t I2C_read_ACK(void)
{

	// start TWI module and acknowledge data after reception
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	// return received data from TWDR
	return TWDR;
}


uint8_t I2C_read_NACK(void)
{
		TWCR = (1 << TWINT) | (1 << TWEN);
		
		while (!(TWCR & (1<<TWINT)));
		return TWDR;
}

