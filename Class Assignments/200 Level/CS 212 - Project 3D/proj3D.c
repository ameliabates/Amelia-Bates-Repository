#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define QUEUE_SIZE 10
typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
   UNSUPPORTED
} MathOperation;

struct queue
{
 int front;
 int population;
 double arr[QUEUE_SIZE];
};
typedef struct queue Queue;
void initializeQueue(Queue *q)
{
    q->front = 0;
    q->population = 0;
}
void enqueue(double value,Queue *q)
/* Your code goes above this line. */
{
    if(q->front > QUEUE_SIZE)
    {
        printf("ERROR ENQUEUE");
        exit(0);
    }
    q->arr[q->front] = value;
    //printf("q->arr is %f\n", q->arr[q->front]);
    q->front++;
    q->population++;
    return;
}
double dequeue(Queue *q)
{
    if(q->front != 0)
    {
        double answer = q->arr[q->front - 1];
        q->population--;
        q->front--;
        //printf("Answer is %f\n", answer);
        return answer;
        
    }
    printf("ERROR DEQUEUE");
    exit(1);
}
void printQueue(struct queue *q)
{
  printf("Printing queue %p\n", q);
  printf("\tThe index for the front of the queue is %d\n", q->front);
  if (q->population == 0)
  {
    printf("\tThe queue is empty.\n");
  }
  else
  {
      
    for (int i = 0; i < q->population; i++)
    {
        
      int index = (q->front + i) % QUEUE_SIZE;
      printf("\t\tEntry[%d]: \"%d\"\n", index, q->arr[index]);
    }
  }
}

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

char a[100];
int main(int argc, char *argv[])
{
    Queue q;
    initializeQueue(&q);
    int j = 1;
    /*
    for (int i = 1; i < argc; i++)
    {
       if (i % 2)
       {
           printf("%s Even\n", argv[i]);
           enqueue(argv[i], q);
       }
       if (!(i %2))
       {
           printf("%s Odd\n", argv[i]);
           enqueue(argv[i], q);
       }
            
    }
    */
    char *v, *v2;
    double total = 0.;
    double result = 0.; 
    for (int i = 1; i < argc; i++)
    {
        char *ch = argv[i];
        //printf("%s\n", ch);
        
            
        if (*ch >= 48 && *ch <= 57)
        {
            double v3 = StringToDouble(argv[i]);
            //printf("Double is %f\n", v3);
            enqueue(v3, &q);
            
        }
        else if ((GetOperation(argv[i]) == SUBTRACT) || (GetOperation(argv[i]) == ADD) || (GetOperation(argv[i]) == MULT))
        {
            
            char str[100];
            MathOperation op = GetOperation(argv[i]);
            double val1 = dequeue(&q);
            double val2 = dequeue(&q);
            switch (op)
            {
            case ADD:
                
                total = val2 + val1;
                //printf("add value 1: %f\n", val1);
                //printf("add value 2: %f\n", val2);
                //printf("add answer is %f\n", (val1 + val2));
                enqueue(val1 + val2, &q);
                break;
            case MULT:
                total = val2 * val1;
                //printf("mult value 1: %f\n", val1);
                //printf("mult value 2: %f\n", val2);
                //printf("mult answer is %f\n", (val1 * val2));
                enqueue(val1 * val2, &q);
                break;
            case SUBTRACT:
                total = val2 - val1;
                //printf("sub value 1: %f\n", val1);
                //printf("sub value 2: %f\n", val2);
                //printf("sub answer is %f\n", (val2 - val1));
                enqueue(val2 - val1, &q);
                break;
            case UNSUPPORTED:
                printf("UNSUPPORTED");
                break;
            }
            
        }
    }
         
    
         
         
        /*
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
       case UNSUPPORTED:
           printf("UNSUPPORTED");
           break;
    }
    */
    
    //printf("%d\n", (int) result);
   printf("The total is %f\n", total);
    return 0;
}
