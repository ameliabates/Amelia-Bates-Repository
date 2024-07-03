#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

  int x = 0xaabbccdd;

  printf("%%d:(%d)\n",x);
  printf("%%u:(%u)\n",x);
  printf("%%x:(%x)\n",x);
  printf("%%#x:(%#x)\n",x);
  printf("%%#20x:(%#20x)\n",x);
  printf("%%#020x:(%#020x)\n",x);
  printf("%%1$#020x %%1$d:(%1$#020x %1$d)\n",x);
  printf("%%#020x:(%#020x)\n",x);
  printf("%%1$#020x %%1$d:(%1$#020x %1$d)\n",x);

}