#include <stdio.h>

int  main() {
   const int a=10;     
    int const *p;           
    p=&a;               
     
    printf("Before changing - value of a: %d",a);
     
   
    *p=20;
     
    printf("\nAfter  changing - value of a: %d",a); 
    printf("\nWauuuu... value has changed.");
     
    return 0;
}