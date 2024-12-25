#include <stdio.h>


long f(long x, long y, long z) 
{
    //subq %rsi, %rdx       z = z - y
    //imulq %rdx, %rdi      x = z * x
    //salq $63, %rdx        z << 63
    //sarq $63, %rdx        z >> 63
    //movq %rdi, %rax       result = x  
    //orq %rdx, %rax        result = z | result
    //ret                   return results
    
    //Assume that x is in %rdi, y is in %rsi, z is in %rdx, and that %rax is used to hold the return value.
    int result;
    z = z - y;
    x = z * x;
    z <<= 63;
    z >>= 63;
    result = x;
    result = z | result;
    return result;
    
}

int main()
{
    printf("f(1, 2, 4): %ld\n", f(1, 2, 4));            //2
    printf("f(3, 5, 7): %ld\n", f(3, 5, 7));            //6
    printf("f(10, 20, 40): %ld\n", f(10, 20, 40));      //200
    printf("f(30, 50, 70): %ld\n", f(30, 50, 70));      //600
}
