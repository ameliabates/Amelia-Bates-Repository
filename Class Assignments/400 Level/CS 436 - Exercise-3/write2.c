#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * argv[]){
  
  int balance = 0x0012d687; 
  int *ptr = &balance;
  char *name = "abc";

  printf(argv[1],name); 
     
  printf("\n");

  printf("*** balance @ %p = %d 0x%08x name is: %s\n", &balance,balance,balance,name);

  exit(0);

}
