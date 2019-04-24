/*
 * I2C.h
 *
 * Created: 16/01/2018 12:16:34 PM
 *  Author: Zakaria Gomaa
 */ 


#ifndef I2C_H_
#define I2C_H_


#define I2C_READ 0x01
#define I2C_WRITE 0x00
#include <util/twi.h>
#include <avr/io.h>
void I2C_Init(void);
void I2C_start(void);
void I2C_stop(void);
void I2C_write(uint8_t data);
uint8_t I2C_read_ACK(void);
uint8_t I2C_read_NACK(void);



#endif /* I2C_H_ */