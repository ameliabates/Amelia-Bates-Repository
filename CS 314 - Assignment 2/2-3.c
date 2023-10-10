#include <stdio.h>

int ge(float x, float y)
{
    unsigned int ux = *((unsigned int*) &x); //convert x raw bits
    unsigned int uy = *((unsigned int*) &y); // convert y raw bits
    unsigned int sx = ux >> 31; // extract sign bit of ux
    unsigned int sy = uy >> 31; // extract sign bit of uy
    
    ux <<= 1; // drop sign bit of ux
    uy <<= 1; // drop sign bit of uy
    return (ux == 0 && uy == 0) || (sx < sy) || (sx == 0 && sy == 0 && ux >= uy) || (sx == 1 && sy == 1 && ux <= uy); // return 1 if x >= y, have to account for sign bit
    
}

int main()
{
    printf("ge(0.0f, 0.0f): %d\n", ge(0.0f, 0.0f)); //1
    printf("ge(-0.0f, 0.0f): %d\n", ge(-0.0f, 0.0f)); //1
    printf("ge(0.0f, -0.0f): %d\n", ge(0.0f, -0.0f)); //1
    printf("ge(-0.0f, -0.0f): %d\n", ge(-0.0f, -0.0f)); //1
    printf("ge(1.0f, 1.0f): %d\n", ge(1.0f, 1.0f)); //1
    printf("ge(-1.0f, 1.0f): %d\n", ge(-1.0f, 1.0f)); //0
    printf("ge(1.0f,-1.0f): %d\n", ge(1.0f,-1.0f)); //1
    printf("ge(-1.0f,-1.0f): %d\n", ge(-1.0f,-1.0f)); //1
    printf("ge(-1.0f, 0.0f): %d\n", ge(-1.0f, 0.0f)); //0
    printf("ge(0.0f, -1.0f): %d\n", ge(0.0f, -1.0f)); //1
    printf("ge(1.0f, 0.0f): %d\n", ge(1.0f, 0.0f)); //1
    printf("ge(0.0f, 1.0f): %d\n", ge(0.0f, 1.0f)); //0
    printf("ge(1.0f, 2.0f): %d\n", ge(1.0f, 2.0f)); //0
    printf("ge(2.0f, 1.0f): %d\n", ge(2.0f, 1.0f)); //1
    printf("ge(-1.0f, -2.0f): %d\n", ge(-1.0f, -2.0f)); //1
     printf("ge(-2.0f, -1.0f): %d\n", ge(-2.0f, -1.0f)); //0
    
}
