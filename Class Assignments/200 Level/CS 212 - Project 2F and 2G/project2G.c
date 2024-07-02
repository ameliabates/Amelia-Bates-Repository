#include <stdio.h>
#include <printf.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *f_in;
    int buff_size, *tally;
    char *buffer, c;
 
    f_in = fopen(argv[1], "r");
    if (f_in == NULL)
    {
        printf("File failure\n");
        exit(EXIT_FAILURE);
    }
    c = fgetc(f_in);

    fseek(f_in, 0, SEEK_END);
    buff_size = ftell(f_in);
    fseek(f_in, 0, SEEK_SET);
    
    buffer = malloc(buff_size + 1);
    buffer[buff_size] = '\0';
    fread(buffer, sizeof(char), buff_size, f_in);
    

    tally = malloc(sizeof(int)*(argc-2) * 10);

    
    char all_word[buff_size][buff_size];
    for (int i = 0; i < buff_size; i++)
    {
        for (int j = 0; j < buff_size; j++)
        {
            all_word[i][j] = '\0';
        }
    }
    int all_word_count = 0, x, y, specific_word_count;
    for (int m = 2; m < argc; m++)
    {
    int specific_word_count = 0;
    int j = 0, ctr = 0;
    
    for (int i = 0; i <= buff_size; i++)
    {
        if (buffer[i] == ' ' || buffer[i] == '\0' || buffer[i] == '\n' || buffer[i] == ',' || buffer[i] == '.')
        {
            //all_word[ctr][j] = '\0';
            ctr++;
            j = 0;
        }
        else
        {
            all_word[ctr][j] = buffer[i];
            j++;
        }
    }
    
    for (y = 0; y <ctr; y++)
    {
        
        //printf("%s\n", all_word[y]);
        all_word_count++;
        
        }
    for (x = 0; x <ctr; x++)
    {       
        //printf("Comparing %d %s with %d %s \n", m, argv[m], x, all_word[x]);
        if (strncmp(argv[m], all_word[x], strlen(argv[m])) == 0)
        {
            if ((strlen(argv[m])) == strlen(all_word[x]))
            {
            specific_word_count++;
            //printf("%s\n", all_word[x]);
            }
            
        }
    }
    
    
    printf("The word \"%s\" occurs %d times.\n", argv[m], specific_word_count);
    
    }
    fclose(f_in);
    free(buffer);
    free(tally);
    return 0;
    
}







