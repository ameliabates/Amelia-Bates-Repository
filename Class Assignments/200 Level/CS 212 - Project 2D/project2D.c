#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
   DIV,
   UNSUPPORTED
} MathOperation;

void IssueBadNumberError()
{
    printf("The string does not represent a floating point number.\n");
    exit(EXIT_FAILURE);
}
void IssueBadOperationError()
{
    printf("The string does not represent a valid operation.\n");
    exit(EXIT_FAILURE);
}

MathOperation GetOperation(char *op)
{
    /* Implement me! */
    double count = 0;
    int i = 0;
    while (op[i++] != '\0')
    {
        count += 1;
    }
    //printf("count: %f", count);
    if (count >= 2)
    {
        IssueBadOperationError();
    }
    switch(*op){
        case '+':
            //printf("ADD\n");
            return ADD;
        case 'x':        /* Why is this not working? */
            //printf("MULT\n");
            return MULT;
        case '-':
            //printf("SUBTRACT\n");
            return SUBTRACT;
        case '/':
            //printf("DIV\n");
            return DIV;
        default:
            //printf("UNSUPPORTED\n");
            IssueBadOperationError();
            return UNSUPPORTED;
    }
        
}
double StringToDouble(char *str)
{
    /* Implement me! */
    double num = 0, neg = 1, dec_count = 0, neg_count = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
           continue;
        }
        else if (str[i] == '.')
        {
            dec_count += 1;
            if (dec_count >= 2)
            {
                IssueBadOperationError();
            }
        }
        else if (str[i] == '-')
        {
            neg_count += 1;
            if (str[0] != '-')
            {
                IssueBadOperationError();
            }
            if (neg_count >= 2)
            {
                IssueBadOperationError();
            }
        }
        else
        {
            IssueBadNumberError();
        }
    }
    if (*str == '-') // determine if number is a negative
    {
        str++;
        neg = -1;
    }
    for (int dec_point = 0; *str; str++)
    {
        if (*str == '.')
        {
            dec_point = 1;
            
        }
        int current = *str - '0';
        if (current >= 0 && current <= 9)
        {
            if (dec_point)neg /= 10;
            {
            num = num * 10 + current;

            }
        
        }
        
    }
    //printf("num: %f\n neg:%f \n", num, neg);
   //int result = num * neg;
   
   //printf("result: %f\n", result);
   return num * neg;
}


int main(int argc, char *argv[])
{
    double v = StringToDouble(argv[1]);
    MathOperation op = GetOperation(argv[2]);
    double v2 = StringToDouble(argv[3]);
    double result = 0.;
    switch (op)
    {
       case ADD:
           result = v+v2;
           break;
       case MULT:
           result = v * v2;
           break;
       case SUBTRACT:
           result = v - v2;
           break;
       case DIV:
           result = v / v2;
           break;
       case UNSUPPORTED:
           printf("UNSUPPORTED");
           break;
    }
    printf("%d\n", (int) result);
 
    return 0;
}
