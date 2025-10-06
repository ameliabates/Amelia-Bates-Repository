#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(char *s)
{
    int length = 0;
    /* Return the length of string s using the C convention of
     * being terminated by the NULL character. 
     * Do not call any other functions whatsoever.
     * Even my_strlen -- no solutions involving recursion. */
    for( int i = 0; s[i] != '\0'; i++)
    {
        length++;
    }
    
    return length;
}

void str_reverse(char *str)
{
    /* Modify s to be the reverse string.
     * If s is "hello" when the function is called, then it
     * should be "olleh" when the function is completed. 
     * The only function you can call is my_strlen.
     * Do not call malloc.  */
    
    int length, rev_str;
    length = my_strlen(str);
    /*char reverse[length + 10];
    for(int i = length - 1; i >= 0; i--)
    {
       reverse[j++] = str[i];
       
    }
    printf("%s\n", reverse);
    for(int i = length - 1; i >= 0; i--)
    {
        str[n++] = reverse[i];
        printf("%s", str[n]);
    }
    printf("%s\n", str); */
    for(int i = 0; i < length / 2; i++)
    {
        rev_str = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = rev_str;
    }
}

int main()
{
    char *str = malloc(strlen("hello world")+1);
    strcpy(str, "hello world");
    str_reverse(str);
    if (strcmp(str, "dlrow olleh") == 0)
    {
        printf("Congrats!  You have successfully reversed \"hello world\" to \"%s\"\n", str);
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Project does not work yet.  You reversed \"hello world\" to \"%s\"\n", str);
        exit(EXIT_FAILURE);
    }
}
