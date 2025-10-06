#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

  char * string = "aabbccdd";

  printf("%%s:(%s)\n",string);
  printf("%%20s:(%20s)\n",string);
  printf("%%.5s:(%.5s)\n",string);
  printf("%%20.5s:(%20.5s)\n",string);
  printf("%%-20.5s:(%-20.5s)\n",string);

}