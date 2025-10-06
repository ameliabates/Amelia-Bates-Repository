#include <stdio.h>

int evenBit(unsigned int x)
{
    //printf("int is %x\n", x & 0x55555555);
    return !!(x & 0x55555555); // 0x5 = 0b101 which masks the even bits. the ! returns 0 or 1 depending on if the integer is a zero or not. 
}

int main()
{
    printf("%x\n", evenBit(0x1)); //1
    printf("%x\n", evenBit(0x2)); //0
    printf("%x\n", evenBit(0x3)); //1
    printf("%x\n", evenBit(0x4)); //1
    printf("%x\n", evenBit(0xFFFFFFFF)); //1
    printf("%x\n", evenBit(0xAAAAAAAA)); //0
    printf("%x\n", evenBit(0x55555555)); //1
    
}
