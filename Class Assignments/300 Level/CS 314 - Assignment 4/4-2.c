#include <stdio.h>

long fact(long x) {
 if (x <= 1) {
 return 1;
 }
 return x * fact(x - 1);
}

/*
 long fact(long x) {
  long result = 1;
  __asm__ ("movq %0, %%rdi;" :: "r" (x));
  __asm__ ("movq %0, %%rax;" :: "r" (result));
  __asm__(
  ".LFACT:"
  "cmpq $1, %rdi;" // compare 1 and x
  "jle .LEND;" //x <= 1 then jump to .LEND
  "imulq %rdi, %rax;" // x * result
  "decq %rdi;" //x--
  "jmp .LFACT;" //jump to .LFACT (fact() is called which then modifies the stack pointer by 8 bytes each time)
  ".LEND:" //stop
  );
  __asm__ ("movq %%rax, %0;" : "=r" (result));
  return result;
}
*/
int main()
{
    printf("fact(1): %ld\n", fact(1));
    printf("fact(3): %ld\n", fact(3));
    printf("fact(5): %ld\n", fact(5));
    
}
