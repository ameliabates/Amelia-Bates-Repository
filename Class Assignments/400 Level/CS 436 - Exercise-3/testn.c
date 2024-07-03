#include<stdio.h> 
int main() { 
   int s; 
   printf("1234567%n\n", &s); 
   printf("The value of s is the number of bytes printed out so far: s=%d\n", s); 
   return 0; 
} 