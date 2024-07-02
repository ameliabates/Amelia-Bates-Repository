#include <stdio.h>
#include <math.h>


unsigned int getOffset(unsigned int address) 
{
    // 8 lowest bits from the address;
    // returns the byte offset of the address within its cache block.
    return address & 0xF;
}

unsigned int getTag(unsigned int address) 
{
    // 24 highest bits from the address
    // returns the cache tag for the address.
    
    return (address >> 12);
    // OR
    // return log2(address >> 8);
}

unsigned int getSet(unsigned int address) 
{
    // returns the cache set for the address.
    return (address >> 4) & 0x000000FF;
}

int main()
{
        unsigned int testAddr1 = 0x12345678;
        unsigned int testAddr2 = 0x87654321;
        // uncomment after implementing
        printf("0x%08x: offset - %x, tag - %x, set - %x\n", testAddr1, getOffset(testAddr1), getTag(testAddr1), getSet(testAddr1));
        printf("0x%08x: offset - %x, tag - %x, set - %x\n", testAddr2, getOffset(testAddr2), getTag(testAddr2), getSet(testAddr2));
}
