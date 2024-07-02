#include <stdio.h>
#include <stdlib.h>
#include <time.h>


 void inner(float *u, float *v, int length, float *dest) 
 {
    float sum = 0.0f;
    for (int i = 0; i < length; ++i)
    {
        sum += u[i] * v[i];
    }
    *dest = sum;
 } 


void inner2(float *u, float *v, int length, float *dest) 
{
    int i;
    float sum = 0.0f, sum2 = 0.0f, sum3 = 0.0f, sum4 = 0.0f;
    int limit = length - 3;
    
    //combine 2 elements at a time
    for (i = 0; i < limit; i += 4)
    {
        sum += u[i] * v[i];
        sum2 += u[i+1] * v[i +1];
        sum3 += u[i+2] * v[i +2];
        sum4 += u[i+3] * v[i +3];
        
    }
    
    //Finish any remaining elements
    for (; i < length; i++)
    {
        sum += u[i] * v[i];
    }
    *dest = sum + sum2 + sum3 + sum4;
}
 
int main()
{
    float u[] = {1.0f, 7.0f, 3.0f};
    float v[] = {5.0f, 5.0f, 6.2f};
    int length = 3;
    float dest1, dest2;

    // Call inner function
    inner(u, v, length, &dest1);
    printf("Inner1: %f\n", dest1);
    
    inner2(u,v, length, &dest2);
    printf("Inner2: %f\n", dest2);
    for (size_t size = 100; size < 101; size += 10)
    {
        float u[size], v[size], dest3, dest4;
        
        for (size_t i = 0; i < size; ++i) 
        {
                u[i] = rand()/(double)RAND_MAX < 0.5 ? 0 : 1;
        }
        for (size_t j = 0; j < size; ++j) 
        {
                
                v[j] = rand()/(double)RAND_MAX < 0.5 ? 0 : 1;
        }
        // SUM_ROWS1:
        clock_t start = clock();
        // Do this 100,000 times to exaggerate the time taken.
        for (size_t i = 0; i < 100000; ++i) 
        {
                inner(u, v, size, &dest3);
        }
        clock_t end = clock();
        double totalTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;
        // SUM_ROWS2:
        
        start = clock();
        // Do this 100,000 times to exaggerate the time taken.
        for (size_t i = 0; i < 100000; ++i) {
                inner2(u, v, size, &dest4);
        }
        end = clock();
        double totalTime2 = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("size: %d\n", size);
        printf("sum_rows1: %f, %f\n", totalTime1, dest3);
        printf("sum_rows2: %f, %f\n", totalTime2, dest4);
    }
    
  
}
