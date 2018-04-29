//
// Created by Jake Billings on 4/28/18.
//

#include "endian.h"

unsigned long swap64(unsigned long k)
{
    return ((k << 56) |
            ((k & 0x000000000000FF00) << 40) |
            ((k & 0x0000000000FF0000) << 24) |
            ((k & 0x00000000FF000000) << 8) |
            ((k & 0x000000FF00000000) >> 8) |
            ((k & 0x0000FF0000000000) >> 24)|
            ((k & 0x00FF000000000000) >> 40)|
            (k >> 56)
    );
}
unsigned int swap32(unsigned int k)
{
    return (((k & 0x000000FF) << 24) |
            ((k & 0x0000FF00) <<  8) |
            ((k & 0x00FF0000) >>  8) |
            ((k & 0xFF000000) >> 24));
}
float ReverseFloat( const float inFloat )
{
float retVal;
char *floatToConvert = ( char* ) & inFloat;
char *returnFloat = ( char* ) & retVal;

// swap the bytes into a temporary buffer
returnFloat[0] = floatToConvert[3];
returnFloat[1] = floatToConvert[2];
returnFloat[2] = floatToConvert[1];
returnFloat[3] = floatToConvert[0];

return retVal;
}