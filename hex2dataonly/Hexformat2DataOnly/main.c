#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "parse_struct.h"

unsigned char Line[43];// insert the line of hex file
unsigned char Line_data[10000]; // hold 16 Asci Code of date + '\0'Null operator
unsigned char Ascii_arry[10000];
Struct_HexFormat_t obj;
unsigned long  counter=0; // hold the index of data
unsigned long N_bytes=0;
unsigned int j=0,count=0;
unsigned int i=0;

void Parse_OneLine()
{
    unsigned char i;
    gets(Line);
    if(Line[0]!='*')
    {
        for(i=0; i<32; i++,counter++)
        {
            Line_data[counter]=((Struct_HexFormat_t*)Line)->Data[i]; // parse using casting to get data
        }
        N_bytes+=8;
    }
}

int main()
{

   do
    {
        Parse_OneLine();
    }
    while(Line[0]!='*');

    Line_data[counter+1]='\0';

    for(i=0;i<counter;i+=2)
    {
      printf("0x%c%c,",Line_data[i],Line_data[i+1]);
    }

    return 0;
}

