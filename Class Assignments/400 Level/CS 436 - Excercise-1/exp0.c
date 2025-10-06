#include <stdio.h>
#include <string.h>

/*
Generate initial abc file for vul1.c or vul2.c
*/


int main() {
  int i;
  unsigned char buf[100]; //must use unsigned char due to sign extension 
  FILE *fp;

  memset(buf ,'a', 100);

  fp = fopen("abc", "w");
  fwrite(buf, 1, 100, fp);

  fclose(fp);
}