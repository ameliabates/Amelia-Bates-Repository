#include <stdio.h>
#define N 4
typedef long array_t[N][N];
void transpose(array_t a) {
 for (long i = 0; i < N; ++i) {
 for (long j = 0; j < i; ++j) {
 long t1 = a[i][j];
 long t2 = a[j][i];
 a[i][j] = t2;
 a[j][i] = t1;
 }
 }
}

/*
 .L3:
 movq (%rax), %rcx //long t1 = a[i][j];
 movq (%rdx), %rsi //long t2 = a[j][i];
 movq %rsi, (%rax) // a[j][i] = t1;
 movq %rcx, (%rdx) // a[i][j] = t2;
 addq $8, %rax //8 += t1
 addq $32, %rdx //32 +=t2;
 cmpq %r9, %rax 
 jne .L3
 */

void transposeOpt(long n, long *a) {
    /* this really confused me, so I used chatGPT to help create this function" */
  long i, j;
  for (i = 0; i < n; i += 32) 
  {
    for (j = 0; j < n; j += 8) 
    {
      long *a_i = a + i * n + j;
      long *a_j = a + j * n + i;
      long t1 = *a_i;
      long t2 = *a_j;
      *a_j = t1;
      *a_i = t2;
    }
  }
}




int main()
{
    array_t answer = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    transpose(answer);
    for (long i = 0; i < N; ++i) 
    {
        for (long j = 0; j < N; ++j) 
        {
            printf("%ld ", answer[i][j]);
        }
        printf("\n");
    }
    
    transposeOpt(4, (long *)answer);
    
    for(int i = 0; i < 4; i++)
    {
        for (int j =0; j < 4; j++)
        {
            printf("%ld ", answer[i][j]);
            
        }
        printf("\n");
    }
    return 0;
}

