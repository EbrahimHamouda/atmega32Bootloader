#ifndef PARSE_STRUCT_H_INCLUDED
#define PARSE_STRUCT_H_INCLUDED

#pragma pack(push,1)
typedef struct
{
    unsigned char Start; //:
    unsigned short Data_size; //
    unsigned int Addrass;
    unsigned short TT;
    unsigned char Data[32];
    unsigned short CS;
} Struct_HexFormat_t ;
#pragma pack(pop)



#endif // PARSE_STRUCT_H_INCLUDED
