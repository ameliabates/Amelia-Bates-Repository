#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

  char *s="I'm here";
  int a=0xaaaaaaaa;
  int b=0xbbbbbbbb;

  printf(argv[1],s); // user controls the format
  printf("\n");
}