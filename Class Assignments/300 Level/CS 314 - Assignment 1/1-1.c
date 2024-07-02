#include <stdio.h>


unsigned int combine(unsigned int x, unsigned int y)
{
    unsigned int masked_byte_3, masked_bytes_2_to_0, combined;
    masked_byte_3 = x & 0xff000000; //isolates byte 3 from x
    masked_bytes_2_to_0 = y & 0x00ffffff; //isolates byte 2-0 from y
    combined = masked_byte_3 | masked_bytes_2_to_0; //combines x and y after they are masked
    return combined;
}

unsigned int main()
{
   unsigned int example_1 = combine(0x12345678, 0xABCDEF00); //0x12cdef00
   unsigned int example_2 = combine(0xABCDEF00, 0x12345678); //0xAB345678
   printf("0x%x\n", example_1); //correct
   printf("0x%x\n", example_2); //correct
}
