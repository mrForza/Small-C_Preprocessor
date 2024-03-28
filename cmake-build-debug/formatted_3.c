#include <stdio.h> 


void swap(int* px, int* py) {
 int temp = *px;
 *px = *py;
 
 *py = temp;
}


int main() 
{
 printf("Hello, world!"); 
 getchar(); 
 return 0;
} 