#include <stdio.h>

int main()
{
    int num = 10;
    int i;
    
    while (num <= 500){
        int point = 0;
        for (i = 1; i <= num; i++)
        {
            if (num % i == 0)
            {
                point++;
            }
        }
        
        if (point != 2)
        {
            if ((num % 2) != 0)
            {
                printf("%d is a composite number.\n", num);
            }
            
        }
        num++;
    
    }
    return 0;
    
}
