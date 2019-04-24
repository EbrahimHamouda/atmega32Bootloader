/*
 * Small application.c
 *
 * Created: 3/20/2019 9:19:21 PM
 * Author : ebrah
 */ 

#include <avr/io.h>

int main(void)
{
	DDRA =0xff;  // port a output
	PORTA=0x00; // port a set 
		
    /* Replace with your application code */
    while (1) 
    {
		PORTA ^= (1<<0);
    }
}
