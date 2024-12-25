#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
struct ColorPoint 
{
    long a;
    long r;
    long g;
    long b;
};

struct ColorPoint** create2DArray(int n) 
{
    // Array to hold a pointer to the beginning of each row
    struct ColorPoint **points = (struct ColorPoint **)malloc(n * sizeof(struct ColorPoint *));
    for (int i = 0; i < n; ++i) 
    {
        // Array to holx each row
        points[i] = (struct ColorPoint *)malloc(n * sizeof(struct ColorPoint));
        for (int j = 0; j < n; ++j) 
        {
            // Init the ColorPoint struct
            points[i][j].a = rand();
            points[i][j].r = rand();
            points[i][j].g = rand();
            points[i][j].b = rand();
        }
    }
    return points;
}


long g(struct ColorPoint **points, int n) 
{
    long sum = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            sum += points[i][j].a;
            sum += points[i][j].r;
            sum += points[i][j].g;
            sum += points[i][j].b;
        }
    }
    return sum;
}

long f(struct ColorPoint **points, int n) 
{
    long sum = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            sum += points[j][i].a;
            sum += points[j][i].r;
            sum += points[j][i].g;
            sum += points[j][i].b;
        }
    }
    return sum;
}

void free2DArray(struct ColorPoint** points, int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        free(points[i]);
    }
    free(points);
}

int main()
{
    //TO DO: WRITE HERE
    struct ColorPoint **points = create2DArray(2048);
    
    
    clock_t start = clock();
    for (int i = 0; i < 5000; i++)
    {
        long f_sum = f(points, 2048);
        
        
    }
    clock_t end = clock();
    double totalTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    start = clock();
    for (int i = 0; i < 5000; i++)
    {
        long g_sum = g(points, 2048);

    }
    end = clock();
    double totalTime2 = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    
    free2DArray(points, 2048);
    printf("sum_rows1: %f\n", totalTime1); // 0.000003 for 5000 times called
    printf("sum_rows2: %f\n", totalTime2); // 0.000002 for 5000 times called
    
    // The g function is faster than the f function because the g function has a better miss rate than the f function.  
    return 0;

}


