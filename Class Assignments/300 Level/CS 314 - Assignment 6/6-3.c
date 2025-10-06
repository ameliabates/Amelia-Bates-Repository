#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float f(float *a, int n) 
{
    float prod = 1.0f;
    for (int i = 0; i < n; ++i) 
    {
        if (a[i] != 0.0f)
        {
            prod *= a[i];
        }
    }
    return prod;
}
float g(float *a, int n) 
{
    float prod = 1.0f;
    for (int i = 0; i < n; ++i) 
    {
        prod *= a[i];
        
    }
    return prod;
}

float* createArray(int size) 
{
    float *a = (float *)malloc(size * sizeof(float));
    for (int i = 0; i < size; ++i) 
    {
        // 50% chance that a[i] is 0.0f, random value on the range
        // [0.76, 1.26] otherwise.
        float r = rand()/(float)RAND_MAX;
        a[i] = r < 0.5f ? 0.0f : r + 0.26f;
    }
    return a;
}

int main()
{
    float *a = (float *)malloc(1000 * sizeof(float));
    float *b = (float *)malloc(1000 * sizeof(float));
    
    int count_a = 0, inc_c = 0;
    for (int i = 0; i < 1000; i++)
    {
        a[i] = *createArray(1000);
        //printf("%f\n", a[i]);
        b[i] = a[i];
        if (b[i] == 0.0f)
        {
            b[i] = 1.0f;
            
        }
        //printf("%f\n", a[i]);
        if (a[i] != 0.0f)
        {
            count_a++;
            //printf("HERE\n");
        }
    }
    
    float *c = (float *)malloc(count_a * sizeof(float));
    
    for (int j = 0; j < 1000; j++)
    {
        if (a[j] != 0.0f)
        {
            c[inc_c] = a[j];
            inc_c++;
        }
        
    }
    
    printf("%d\n", inc_c);
    printf("%d\n", count_a);
    clock_t start = clock();
    printf("%f\n", f(a, 1000));
    clock_t end = clock();
    double totalTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    start = clock();
    printf("%f\n", g(b, 1000));
    end = clock();
    double totalTime2 = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    start = clock();
    printf("%f\n", g(c, count_a));
    end = clock();
    double totalTime3 = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("TotalTimes1: %f\n", totalTime1);
    printf("TotalTime2: %f\n", totalTime2);
    printf("TotalTime3: %f\n", totalTime3);
    //  g(b) is faster than f(a) because unlike f(a), g(b) doesn't have to check for a zero in every element of the array
    free(a);
    free(b);
    free(c);
    return 0;
    //printf("%f\n", p);
    
}



