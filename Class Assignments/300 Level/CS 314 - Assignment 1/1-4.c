#include <stdio.h>

void printBytes (unsigned char *start, int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void printInt(int x)
{
    printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x)
{
    printBytes((unsigned char *) &x, sizeof(float));
}

void printShort(short x)
{
    printBytes((unsigned char *) &x, sizeof(short));
}

void printLong(long x)
{
    printBytes((unsigned char *) &x, sizeof(long));
}

void printLongLong(long long x)
{
    printBytes((unsigned char *) &x, sizeof(long long));
}

void printDouble(double x)
{
    printBytes((unsigned char *) &x, sizeof(double));
}

int main()
{
    printInt(13);
    printFloat(2.22);
    printShort(500);
    printLong(800);
    printLongLong(101010101);
    printDouble(12.329498324343);
    /*
     Observations:
     -int and float have the same byte length, according to the textbook this makes sense because in a 64-bit program they both have 4 bytes
     -long, long long, and double also have the same byte length, according to the textbook this makes sense because in a 64-bit program they both have 8 bytes
     
     
     */
}
