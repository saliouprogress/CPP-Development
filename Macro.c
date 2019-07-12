    
#include <stdio.h>

//#include DEFS_H
#define PRINT1
#define PRINT2



int main()
{

int a, b;
scanf("%d %d", &a, &b);
//int TEST();
printf("\n%d %d", a,b);

#ifdef PRINT1 // test whether MACRO1 is defined...
printf("\nMACRO1 Defined %d\n", a);
#endif

#ifdef PRINT2 // test whether MACRO2 is defined...
 printf("\nMACRO2 Defined %d , %d\n", a,b);
#endif

return 0;
}
