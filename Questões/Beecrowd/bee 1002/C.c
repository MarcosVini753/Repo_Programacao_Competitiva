#include <stdio.h>

int main(void){
   double area, n = 3.14159, raio;
   scanf("%lf", &raio);
   area = raio * n * raio;
   printf("A=%.4lf\n", area);
   return 0;
}