#include <stdio.h>

/* Used chatgpt to help come up with the replaced function, however, I changed it around and condenced it*/
unsigned int replace(unsigned int x, int i, unsigned char b)
{
    unsigned int replaced;
    replaced = x & ~(0xFF << (i << 3)) | (b << (i << 3)); //replace byte i with b by creating a mask to isolate i and then align b into the unsigned int
    return replaced;
}
unsigned int main()
{
    unsigned int answer1, answer2;
    answer1 = replace(0x12345678, 3, 0xAB); //0xAB345678
    answer2 = replace(0x12345678, 0, 0xAB); //0x123456AB
    printf("0x%x\n", answer1); //correct
    printf("0x%x\n", answer2); //correct
}
