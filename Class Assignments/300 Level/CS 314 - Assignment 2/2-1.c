#include <stdio.h>

unsigned int mask(int n)
{
    unsigned int shifted, masked;
    shifted = 1 << n; //shifts 1 left n units
    masked = shifted - 1; //bit mask containg 1st for the least significant n bits
    return masked;
}

int main()
{
    printf("Mask(1): 0x%x\n", mask(1));   //0x1
    printf("Mask(2): 0x%x\n", mask(2));   //0x3
    printf("Mask(3): 0x%x\n", mask(3));   //0x7
    printf("Mask(5): 0x%x\n", mask(5));   //0x1F
    printf("Mask(8): 0x%x\n", mask(8));   //0xFF
    printf("Mask(16): 0x%x\n", mask(16)); //0xFFFF
    printf("Mask(31): 0x%x\n", mask(31)); //0x7FFFFFFF
    
}
