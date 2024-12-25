#include <stdio.h>

unsigned int extract(unsigned int x, int i)
{
    unsigned int replaced;
    replaced = (x >> (8 * i)) & 0xFF;  //shift to least sig position and then mask more significant vytes
    return (signed char) replaced; //extends to 32 bits
}

int main()
{
    printf("extract(0x12345678, 0): 0x%x\n", extract(0x12345678, 0));
    printf("extract(0xABCDEF00, 2): 0x%x\n", extract(0xABCDEF00, 2));
    
}
