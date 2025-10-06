#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IntArray
{
    int length;
    int *dataPtr;
};

struct IntArray* mallocIntArray(int length)
{
    struct IntArray *new_intArray = malloc(sizeof (int)); //new struct allocated
    new_intArray->length = length;
    new_intArray->dataPtr = malloc(length * sizeof(int)); //allocate instance's dataPtr
    
    return new_intArray;
}

void freeIntArray(struct IntArray *arrayPtr)
{
    
    //important to free memory that is allocated
    free(arrayPtr->dataPtr); //frees the array point
    free(arrayPtr); //frees the array
}

void readIntArray(struct IntArray *array)
{
    
        int len;
        char interger[100];
        char *ptr = NULL;
        long ret;
        int i = 0;
        
        for (i = 0; i < array->length; i++)
        {
            printf("Enter int: "); //Prompts user
            scanf("%s", interger);
            ret = strtol(interger, &ptr, 10);
            if(strlen(ptr) > 0)
            {
                printf("Invalid Int\n");
                i--; //subtracts 1 from i because the invalid int is not counted
                continue; //prompts user again
            }
            
            len = ret;
            array->dataPtr[i] = len; //adds to the array
            //printf("HERE");
        }
            /*
                // char* fgets (char* str, int num, FILE* stream);
                fgets(lineBuf, sizeof(lineBuf), stdin);

                // long int strtol (const char* str, char** endptr, int base);
                *n = strtol(lineBuf, &p, 10);
                if (lineBuf > 0) {
                        array[array->length].dataPtr = n;
                        array->length++;
                        break;
                }
                else 
                {
                printf("Invalid input\n");
                }
                */
        

}


void swap(int *xp, int *yp)
{
    //swaps the position of xp and yp
    int temporary = *xp;
    *xp = *yp;
    *yp = temporary;
}

void sortIntArray(struct IntArray *array)
{
        //Used geeksforgeeks
    
    int i, j;
    for(i = 0; i < array->length - 1; i++)
    {
        for (j = 0; j < array->length - i -1; j++)
        {
            if (array->dataPtr[j] > array->dataPtr[j+1]) // if the next integer is less than the current one then they swap places
            {
                swap(&array->dataPtr[j], &array->dataPtr[j+1]);
            }
        }
    }
}

void printIntArray(struct IntArray *array)
{
    //also used geeksforgeeks for this function
    
    int i;
    printf("[ ");
    for (i = 0; i < array->length ; i++)
    {
        printf("%d ", array->dataPtr[i]); //prints the integer
    }
    printf("]\n");
}


int main()
{
    int len;
    char interger[100];
    char *ptr = NULL;
    long ret;
    while (1)
    {
        
        printf("Enter length: "); //prompts user
        scanf("%s", &interger);
        //printf("%d\n", len);
        ret = strtol(interger, &ptr, 10);
        if (strlen(ptr) > 0)
        {
            printf("Invalid Input\n");
            continue; //prompts user again
        }
        len = ret;
        struct IntArray* newarray = mallocIntArray(len);
        readIntArray(newarray);
        
        sortIntArray(newarray);
        printIntArray(newarray);
        freeIntArray(newarray);
        return 0; 
    }
    return 0;
}
