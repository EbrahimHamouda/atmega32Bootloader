/*
 * External_EEPROM.h
 *
 * Created: 10/02/2018 03:08:43 PM
 *  Author: Zakaria Gomaa
 */ 


#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

#include "I2C.h"
#include <avr/io.h>

#define EEPROM_DEVICE_ADDR 0xA0
#define EEPROM_PAGE_SIZE   8
/******************************* Macros *****************************/
#define EEPROM_Init()                 I2C_Init() 
#define EEPROM_Write_Page(addr,buf)   EEPROM_Write_Len(addr , EEPROM_PAGE_SIZE , buf)
#define EEPROM_Read_Page(addr,buf)    EEPROM_Read_Len( addr  , EEPROM_PAGE_SIZE , buf) 

/******************************** Functions Prototypes **************/

void EEPROM_Write( uint16_t addr, uint8_t dat);
uint8_t EEPROM_Read( uint16_t addr);
void EEPROM_Write_Len( uint16_t addr, uint8_t len, uint8_t *buf);
void EEPROM_Read_Len( uint16_t addr, uint16_t len, uint8_t *buf);

#endif /* EXTERNAL_EEPROM_H_ */