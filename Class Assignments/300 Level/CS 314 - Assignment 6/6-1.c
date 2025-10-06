#include <stdio.h>

/*
 int f(int a, int b, int c, int d, int n) 
 {
    int result = 0;
    for (int i = 0; i < n; i += 2) 
    {
        for (int j = 0; j < n; j += 2) 
        {
            result += a * b + i * c * d + j;
        }
    }
    return result;
 }
 */

int f(int a, int b, int c, int d, int n) 
{
    //Rewrite the above procedure f to remove all multiplications from inside the loops (you may still perform multiplication outside the loops – i.e., O(1) multiplicatons).
    int result = 0;
    int ab = a * b, cd = c * d, icd = 0;
    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < n; j += 2)
        {
            result += ab + icd + j; //no multiplication in inside the loops
        }
        icd += cd + cd; //because i goes up by two add cd twice
        
    }
    return result;
}

int main()
{
    printf("f(1, 2, 3, 4, 5): %d\n", f(1, 2, 3, 4, 5)); //f(1, 2, 3, 4, 5): 252
    printf("f(2, 3, 4, 5, 6): %d\n", f(2, 3, 4, 5, 6)); //f(2, 3, 4, 5, 6): 432
    printf("f(6, 5, 4, 3, 2): %d\n", f(6, 5, 4, 3, 2)); //f(6, 5, 4, 3, 2): 30
    printf("f(5, 4, 3, 2, 1): %d\n", f(5, 4, 3, 2, 1)); //f(5, 4, 3, 2, 1): 20
}
