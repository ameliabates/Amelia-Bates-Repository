/* CS 212 Project: Donations (2022)
   ~Always appreciated, never expected, non-refundable~

   Author: S. Isaac Geronimo Anderson (Fall 2022)
   */

#include <stdio.h>   /* printf */
#include <stdlib.h>  /* malloc */
#include <string.h>  /* strcmp */

/* Do not change these values for your submission. */
#define QUEUE_SIZE 12  /* Note: Works with 12 on 3C-input.txt */
#define BLOOD_TYPES 4
#define LINE_LENGTH 80

/* Your code goes below this line. */

struct queue
{
  /* Add your struct members here. */
  int front;
  int back;
  char *strings[QUEUE_SIZE];
  int population;
};
typedef struct queue Queue;


void initializeQueue(Queue *q)
{
    q->front = 0;
    q->back = 0;
    q->population = 0;
}
void enqueue(char *str,Queue *q)
/* Your code goes above this line. */
{
    //fprintf(stderr, "HERE AT ENUEUE");
    if (q->population == QUEUE_SIZE)
    {
        fprintf(stderr, "ENQUEUE ERROR");
    }
    //fprintf(stderr, "Made it Here");
    q->strings[q->back] = strdup(str);
    //fprintf(stderr, "Made it Here");
    q->back = (q->back + 1) % QUEUE_SIZE;
        //fprintf(stderr, "Made it Here");
    
    q->population++;
}
char* dequeue(Queue *q)
{
    if (q->population == 0)
    {
        printf("DEQUEUE ERROR");
    }
    //printf("0. %s\n", q->strings[0]);
    char *rv = q->strings[q->front];
    //int st_front = q->front;
    //printf("0. %s\n", rv);
    //printf("%d\n", q->population);
    //for (int i = 0; i < q->population - 1; i++)
    //{
        
      //  q->strings[i] = q->strings[i+1];
        //printf("%s\n", q->strings[i]);
       
    //}
    
   // printf("Answer: %s\n", q->strings[st_front]);
    q->population--;
    q->front = (q->front + 1) % QUEUE_SIZE;
    //printf("HERE\n");
    //printf("Answer: %s\n", *q->strings);
    //printf("HERE\n");
    return rv;
    
    
}

/* Here is a suggested helper function for checking blood type
   compatibility. */
int isDonorToRecipient(char *donor, char *recipient)
{
  if (strcmp(donor, "O") == 0 || strcmp(donor, recipient) == 0)
    return 1;
  if (strcmp(donor, "A") == 0 && strcmp(recipient, "AB") == 0)
    return 1;
  if (strcmp(donor, "B") == 0 && strcmp(recipient, "AB") == 0)
    return 1;
  return 0;
}


/* Uncomment printQueue and prettyPrintQueue when your queue struct
   and functions are implemented. */

void printQueue(struct queue *q)
{
  printf("Printing queue %p\n", q);
  printf("\tThe index for the front of the queue is %d\n", q->front);
  printf("\tThe index for the back of the queue is %d\n", q->back);
  if (q->population == 0)
  {
    printf("\tThe queue is empty.\n");
  }
  else
  {
    for (int i = 0; i < q->population; i++)
    {
      int index = (q->front + i) % QUEUE_SIZE;
      printf("\t\tEntry[%d]: \"%s\"\n", index, q->strings[index]);
    }
  }
}


void prettyPrintQueue(struct queue *q, char *label, char *type)
{
  if (q->population == 0)
  {
    printf("No unmatched entries for %s (%s)\n", label, type);
  }
  else
  {
    printf("Unmatched %s (%s):\n", label, type);
    for (int i = 0; i < q->population; i++)
    {
      int index = (q->front + i) % QUEUE_SIZE;
      printf("%s\n", q->strings[index]);
    }
  }
}



int main(int argc, char **argv)
{
  /***  STEP #1: Implement your queue code and test it.  ***/

  /* This test code: */
  /*
  struct queue *q = malloc(sizeof (struct queue));
  initializeQueue(q);
  printQueue(q);
  enqueue("hello", q);
  printQueue(q);
  enqueue("world", q);
  printQueue(q);
  printf("Dequeue: %s\n", dequeue(q));
  printQueue(q);
  free(q);
  */
  /*
  Gives this output (with different pointers):

Printing queue 0x7fff5e6878a8
	The index for the front of the queue is 0
	The index for the back of the queue is 0
	The queue is empty.
Printing queue 0x7fff5e6878a8
	The index for the front of the queue is 0
	The index for the back of the queue is 1
		Entry[0] = "hello"
Printing queue 0x7fff5e6878a8
	The index for the front of the queue is 0
	The index for the back of the queue is 2
		Entry[0] = "hello"
		Entry[1] = "world"
Dequeue: hello
Printing queue 0x7fff5e6878a8
	The index for the front of the queue is 1
	The index for the back of the queue is 2
		Entry[1] = "world"
  
*/
  /***
    STEP #2: Open the input file (argc/argv stuff).
             You should read the file line-by-line in the next step
             using fgets (or fscanf or getline).
             Note: You must not hard-code the input file name.
             You must not use fread.
             You should exit with an error if file opening fails.
  ***/
 
FILE* input;
input = fopen(argv[1], "r");
char *buffer_to_store = malloc(LINE_LENGTH*sizeof(char));
if (input == NULL)
{
    exit(1);
}




  /***
    STEP #3: After your queue code works and after you can read the
             file, implement the prompt.
             Note: Here is the print statement to use for a match:

  printf(
      "MATCH: %s donates to %s via Dr. %s\n",
      donor,
      recipient,
      surgeon);

    You will need four queues for recipients, and four queus for
    donors, so using arrays seems sensible. Suggested declarations
    for these arrays are included below this comment.

  ***/

  /* Here is a suggested helper array for facilitating matching as
    described in the prompt. The blood types are listed from most
    rare to least rare. */
  char *types[BLOOD_TYPES] = {"AB", "B", "A", "O"};
  
  const char s[2] = ":";
  
  struct queue *donors[BLOOD_TYPES];
  struct queue *recipients[BLOOD_TYPES];
  struct queue *surgeons = malloc(sizeof *surgeons);
  for (int i = 0; i < BLOOD_TYPES; i++)
  {
      donors[i] = malloc(sizeof *donors[i]);
      recipients[i] = malloc(sizeof *recipients[i]);
  }
  initializeQueue(surgeons);
  initializeQueue(donors[3]);

while(fgets(buffer_to_store, LINE_LENGTH, input))
{
    
    //printf("Line is: %s\n", buffer_to_store);
 
    //char *token;
    char *buff = (char *)malloc(strlen(buffer_to_store) +1);
    strcpy(buff, buffer_to_store);
    //token = strtok(buff, s);
    char *ptc;
    char *token[4];
    ptc = strtok(buff, ":");
    
    token[0] = ptc;
    //printf("%s\n", token[0]);
    ptc = strtok(NULL, ":\n");
    if ((strcmp("R", *token) == 0) || (strcmp("D", *token) == 0))
    {
        token[1] = ptc;
        //printf("%s\n", token[1]);
        ptc = strtok(NULL, ":\n");
        
        token[2] = ptc;
        //printf("%s\n", token[2]);
        ptc = strtok(NULL, ":\n");
    }
    if (strcmp("S", *token) == 0)
    {
        token[3] = ptc;
        //printf("%s\n", token[3]);
        ptc = strtok(NULL, ":\n");
    }
    
    
    
    
    
        if (strcmp(token[0], "D") == 0)
        {
            if (surgeons->population == 0)
            {
                
                for (int i = 0; i < BLOOD_TYPES; i++)
                {
                    
                    if (strcmp(types[i], token[1]) == 0)
                    {
                        enqueue(token[2], donors[i]);
                        
                        
                    }
                }
                
                //token = strtok(NULL, s);
            }
            else
            {
                
                //for (int i = 0; i < BLOOD_TYPES; i++)
                {

                    //if (strcmp(types[i], token[1]) == 0)
                    {
                        //printQueue(recipients[0]);
                        if ((recipients[0]->population != 0) && (isDonorToRecipient(token[1], "AB") == 1))
                        {
                            
                            
                            
                                char *r = dequeue(recipients[0]);
                                char *s = dequeue(surgeons);
                                printf("MATCH: %s donates to %s via Dr. %s \n", token[2], r, s);
                                //printf("donor here!\n");
                                //dequeue(recipients[0]);
                                //dequeue(surgeons);
                                //printQueue(surgeons);
                            
                        }
                        else if ((recipients[1]->population != 0) && (isDonorToRecipient(token[1], "B") == 1))
                        {
                            
                            {
                                char *r = dequeue(recipients[1]);
                                char *s = dequeue(surgeons);
                                printf("MATCH: %s donates to %s via Dr. %s \n", token[2], r, s);
                                //printf("Recipient here!\n");
                                //dequeue(recipients[1]);
                                //dequeue(surgeons);
                            }
                        }
                        else if ((recipients[2]->population != 0) && (isDonorToRecipient(token[1], "A") == 1))
                        {
                            
                            {
                                char *r = dequeue(recipients[2]);
                                char *s = dequeue(surgeons);
                                printf("MATCH: %s donates to %s via Dr. %s \n", token[2], r, s);
                                //printf("Recipient here!\n");
                                //dequeue(recipients[2]);
                                //dequeue(surgeons);
                            }
                        }
                        else if ((recipients[3]->population != 0) && (isDonorToRecipient(token[1], "O") == 1))
                        {
                            
                            {
                                char *r = dequeue(recipients[3]);
                                char *s = dequeue(surgeons);
                                printf("MATCH: %s donates to %s via Dr. %s \n", token[2], r, s);
                                //printf("Recipient here!\n");
                                //dequeue(recipients[3]);
                                //dequeue(surgeons);
                            }
                        }
                        else
                        {
                            //printf("HER");
                            for (int i = 0; i < BLOOD_TYPES; i++)
                            {

                                if (strcmp(types[i], token[1]) == 0)
                                {
                                    //printf("Donor is enqued into %d\n", i); 
                                    enqueue(token[2], donors[i]);
                                     break;
                                }
                           
                            }
                        }
                    }
                }
            }
            
            
        }
        
        else if (strcmp(token[0], "R") == 0) 
        {
            //token = strtok(NULL, s);
            if (surgeons->population == 0)
            {
                for (int i = 0; i < BLOOD_TYPES; i++)
                {

                    if (strcmp(types[i], token[1]) == 0)
                    {
                        //token = strtok(NULL, s);
                        //printf("token is %s", token);
                        enqueue(token[2], recipients[i]);
                        
                        
                    }
                }
                
            }
            else
            {
              
                {

                    
                    {
                        
                        if ((donors[0]->population != 0) && (isDonorToRecipient("AB", token[1]) == 1))
                        {
                            //printf("HERE 1\n");
                            
                            {
                                char *d = dequeue(donors[0]);
                                char *s = dequeue(surgeons);
                                printf("MATCH: %s donates to %s via Dr. %s \n", d, token[2], s);
                                //printf("Recipient here!\n");
                                //dequeue(donors[0]);
                                //dequeue(surgeons);
                            }
                        }
                        else if ((donors[1]->population != 0) &&  (isDonorToRecipient("B", token[1]) == 1))
                        {
                            //printf("HERE 2\n");
                            {
                                
                                char *d = dequeue(donors[1]);
                                char *s = dequeue(surgeons);
                                printf("MATCH: %s donates to %s via Dr. %s \n", d, token[2], s);
                                //printf("Recipient here!\n");
                                //dequeue(donors[1]);
                                //dequeue(surgeons);
                            }
                        }
                        else if ((donors[2]->population != 0) &&  (isDonorToRecipient("A", token[1]) == 1))
                        {
                            //printf("HERE 3\n");
                            
                            {
                                
                                char *d = dequeue(donors[2]);
                                char *s = dequeue(surgeons);
                                printf("MATCH: %s donates to %s via Dr. %s \n", d, token[2], s);
                                //printf("Recipient here!\n");
                                //dequeue(donors[2]);
                                //dequeue(surgeons);
                            }
                        }
                        else if ((donors[3]->population != 0) && (isDonorToRecipient("O", token[1]) == 1))
                        {
                            //printf("HERE 4\n");
                            
                            {
                                char *d = dequeue(donors[3]);
                                char *s = dequeue(surgeons);
                                printf("MATCH: %s donates to %s via Dr. %s \n", d, token[2], s);
                                //printf("Recipient here!\n");
                                
                                
                        }
                        }
                        else
                        {
                            for (int i = 0; i < BLOOD_TYPES; i++)
                            {

                                if (strcmp(types[i], token[1]) == 0)
                                {
                                    enqueue(token[2], recipients[i]);
                                     break;
                                }
                           
                            }
                        }
                    }
                }
            }
            
           
        }
        
        else if (strcmp(token[0], "S") == 0) 
        {
            
            //token = strtok(NULL, s);
            
            //printf("HERE\n");
            //printf("AB is %d\n", (donors[0]->population) );
            if (((donors[0]->population) != 0)&& ((recipients[0]->population) != 0))//DONT KNOW HOW TO
            {
                char *d = dequeue(donors[0]);
                char *r = dequeue(recipients[0]);
                printf("MATCH: %s donates to %s via Dr. %s \n", d, r, token[3]);
                //dequeue(donors[0]);
                //dequeue(recipients[0]);
                //token = strtok(NULL, s);
            }
            else if  (((donors[1]->population) != 0 && (recipients[0]->population) != 0))
                {
                 char *d = dequeue(donors[1]);
                char *r = dequeue(recipients[0]);
                printf("MATCH: %s donates to %s via Dr. %s \n", d, r, token[3]);
                //dequeue(donors[1]);
                //dequeue(recipients[0]);
                //token = strtok(NULL, s);
            }
            else if  (((donors[2]->population) != 0) && (recipients[0]->population != 0))
                {
                    
                 char *d = dequeue(donors[2]);
                char *r = dequeue(recipients[0]);
                printf("MATCH: %s donates to %s via Dr. %s \n", d, r, token[3]);
                //dequeue(donors[2]);
                //dequeue(recipients[0]);
                //token = strtok(NULL, s);
            }
            else if (((donors[3]->population) != 0) && ((recipients[0]->population) != 0))
                {
             char *d = dequeue(donors[3]);
                char *r = dequeue(recipients[0]);
                printf("MATCH: %s donates to %s via Dr. %s \n", d, r, token[3]);
                
                //dequeue(donors[3]);
                //dequeue(recipients[0]);
                //token = strtok(NULL, s);
            }
            else if (((donors[1]->population) != 0) && ((recipients[1]->population) != 0))
                {
                char *d = dequeue(donors[1]);
                char *r = dequeue(recipients[1]);
                printf("MATCH: %s donates to %s via Dr. %s \n", d, r, token[3]);
                //dequeue(donors[1]);
                //dequeue(recipients[1]);
                //token = strtok(NULL, s);
            }
             else if (((donors[3]->population) != 0) && ((recipients[1]->population) != 0))
                {
                 char *d = dequeue(donors[3]);
                char *r = dequeue(recipients[1]);
                printf("MATCH: %s donates to %s via Dr. %s \n", d, r, token[3]);
                //dequeue(donors[3]);
                //dequeue(recipients[1]);
                //token = strtok(NULL, s);
                }
            else if  (((donors[2]->population) != 0) && ((recipients[2]->population) != 0))
                {
                 char *d = dequeue(donors[2]);
                char *r = dequeue(recipients[2]);
                printf("MATCH: %s donates to %s via Dr. %s \n", d, r, token[3]);
                //dequeue(donors[2]);
                //dequeue(recipients[2]);
                //token = strtok(NULL, s);
                }
            else if (((donors[3]->population) != 0) && ((recipients[2]->population) != 0))
                {
                 char *d = dequeue(donors[3]);
                char *r = dequeue(recipients[2]);
                printf("MATCH: %s donates to %s via Dr. %s \n", d, r, token[3]);
                //dequeue(donors[3]);
                //dequeue(recipients[2]);
                //token = strtok(NULL, s);
                }
            else if (((donors[3]->population) != 0) && ((recipients[3]->population) != 0))
                {
                 char *d = dequeue(donors[3]);
                char *r = dequeue(recipients[3]);
                printf("MATCH: %s donates to %s via Dr. %s \n", d, r, token[3]);
                
                //dequeue(donors[3]);
                //dequeue(recipients[3]);
                //token = strtok(NULL, s);
                }
            
            
            else
                {
                    enqueue(token[3], surgeons);
                    //break;
                    
                }
        
         
        }
        
       //token = strtok(NULL, s); //KEEP AT THE END OF ALL THE IF STATEMENTS
    }
  
    

       
        


  /***
    STEP #4: After your matching code is done, add prettyPrintQueue
             calls for each of your recipient queues, your donor
             queues, and your surgeon queue. If you used the
             suggested "recipients" and "donors" arrays, and the
             "types" array, then you can use these print statements:

  for (int r = 0; r < BLOOD_TYPES; r++)
    prettyPrintQueue(recipients[r], "recipients", types[r]);
  for (int d = 0; d < BLOOD_TYPES; d++)
    prettyPrintQueue(donors[d], "donors", types[d]);
  prettyPrintQueue(surgeons, "surgeons", "type-agnostic");

             If you did not use arrays for your recipient and donor
             queues, then you should print your recipient queues in
             this order, for example:

  prettyPrintQueue(recipients_AB, "recipients", "AB");
  prettyPrintQueue(recipients_A, "recipients", "B");
  prettyPrintQueue(recipients_B, "recipients", "A");
  prettyPrintQueue(recipients_O, "recipients", "O");

             Then, print your donor queues in the same order, then
             print your surgeon queue.
  ***/
  for (int r = 0; r < BLOOD_TYPES; r++)
    prettyPrintQueue(recipients[r], "recipients", types[r]);
  for (int d = 0; d < BLOOD_TYPES; d++)
    prettyPrintQueue(donors[d], "donors", types[d]);
  prettyPrintQueue(surgeons, "surgeons", "type-agnostic");
  /* If you have time, be sure to free any memory you allocated. */
  free(surgeons);
  fclose(input);
  return EXIT_SUCCESS;
}


/* End. */
