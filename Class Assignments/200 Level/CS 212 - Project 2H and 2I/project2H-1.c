#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int *AllocateArray(int N)
{
    /* Allocate an array with N integers.
     * The value of each element of the array should be a
     * random number between 0 and 10N.
     * Hint: use the rand() function and a modulo operator.
     */
    int i, *rand_array;
    rand_array = (int*)malloc(N * sizeof(int));
    //printf("N is %d\n", N);
    for (i = 0; i < N; i++)
    {
        //printf("random integer is %d\n", rand_int);
        rand_array[i] = rand() % (10*N);
        //printf("%d\n", rand_array[i]);
    }
   
    return rand_array;
}
int comparator(const void *p, const void *q)
{
    
    return (*(int *)p - *(int *)q);
}
void SortArray(int *A, int N)
{
    /* Hint: pull your code from 2B */
    /*int  i, j, sorted;
    for (i = 0; i < N; ++i)
    {
        for (j = i + 1; j < N ; ++j)
        {
            if (*(A+j) < *(A+i))
            {
                sorted = *(A + i);
                *( A + i) = *(A + j);
                *(A +j)= sorted;
            }
        } 
    } */
    int size = N / sizeof(A[0]);
    qsort((void*)A, N, sizeof(int), comparator);
    /*printf("SORTED\n");
    for (int i = 0; i < N; ++i)
    {
        printf("%d\n", A[i]);
    }*/
    

/*
for (int i = 0; i < N; ++i)
    {
        printf("%d\n", *(A + i));
    }
*/
}

void DeallocateArray(int *A)
{
    free(A);
}

int main()
{
    int sizes[8] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000 };

/* For fun:
 *  int sizes[11] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000,
 *                    256000, 512000, 1024000 }; 
 */

    for (int i = 0 ; i < 8 ; i++)
    {
        int *p, *A;
        double alloc_time = 0., sort_time = 0., dealloc_time = 0.;
        struct timeval startTime;
        gettimeofday(&startTime, 0);

        //printf("NON Sorted\n");
        p = AllocateArray(sizes[i]);
        //p = AllocateArray(10);
        /*for (int i = 0; i < 10; ++i)
        {
            printf("%d\n", p[i]);
        }*/
        //SortArray(p, sizes[i]);
        
        //DeallocateArray(p);
        struct timeval endTime;
        gettimeofday(&endTime, 0);
        
        alloc_time = (endTime.tv_sec - startTime.tv_sec) +
                     (endTime.tv_usec - startTime.tv_usec) / 1000000.;
      
        
        
        printf("Timings for array of size %d\n", sizes[i]);
        printf("\tTime for allocation is %g, time per element = %g\n", alloc_time, alloc_time/sizes[i]);
        struct timeval startTime2;
        gettimeofday(&startTime2, 0);

        //printf("NON Sorted\n");
        //p = AllocateArray(sizes[i]);
        
        //printf("SORTED\n");
        SortArray(p, sizes[i]);
        //SortArray(p, 10);
        //DeallocateArray(p);
        struct timeval endTime2;
        gettimeofday(&endTime2, 0);
        
        //alloc_time = (endTime.tv_sec - startTime.tv_sec) +
                     //(endTimek.tv_usec - startTime.tv_usec) / 1000000.;
        
        sort_time = (endTime2.tv_sec - startTime2.tv_sec) +
                     (endTime2.tv_usec - startTime2.tv_usec) / 1000000.;
        printf("\tTime for sort_time is %g, time per element = %g\n", sort_time, sort_time/sizes[i]);
        struct timeval startTime3;
        gettimeofday(&startTime3, 0);

        //printf("NON Sorted\n");
        //p = AllocateArray(sizes[i]);
        
        //printf("SORTED\n");
        //SortArray(p, sizes[i]);
        
        DeallocateArray(p);
        struct timeval endTime3;
        gettimeofday(&endTime3, 0);
        
        dealloc_time = (endTime3.tv_sec - startTime3.tv_sec) +
                     (endTime3.tv_usec - startTime3.tv_usec) / 1000000.;
        printf("\tTime for deallocation is %g\n", dealloc_time);
        
    }
}
