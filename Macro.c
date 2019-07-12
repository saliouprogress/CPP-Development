    
#include <stdio.h>

//#include "Defs.h"

int main()
{

int a, b;
scanf("%d %d", &a, &b);

printf("\n%d %d", a,b);
return 0;
}
///////////////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
 #define MACRO(x)  x * (x+5)
 int main(void)
 { 
#ifdef MACRO // test whether MACRO1 is defined...    
 printf("\nMACRO Defined...\n"); 
#endif     
int res = MACRO(2);     
printf("\n res = [%d]\n", res);    
 return 0;
 }
