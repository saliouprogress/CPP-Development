#include <stdio.h>

//#include DEFS_H
#define PRINT1
#define PRINT2
#define MAX2(x, y) (((x) > (y)) ? (x) : (y))
#define MAX3(x,y,z) (((MAX2(x, y)) > (z)) ? (MAX2(x, y)) : (z))


int main()
{

int a, b, c;
scanf("%d %d %d", &a, &b, &c);
//int TEST();
printf("\nx = %d, y = %d, z = %d", a,b,c);
int x =a, y = b, z = c;
                ////////
#ifdef PRINT1 // test whether PRINT1 is defined...
printf("\nPRINT1 Defined %d\n", a);
#endif
                ///////
#ifdef PRINT2 // test whether PRINT2 is defined...
 printf("\nPRINT2 Defined %d , %d\n", a,b);
#endif
                ///////
#ifdef MAX2 // test whether MAX2 is defined...    
 printf("\nMAX2 Defined...\n"); 
#endif     
int res2 = MAX2(x,y);     
printf("\n res2 = [%d]\n", res2);   
                ////////
#ifdef MAX3 // test whether MAX3 is defined...    
 printf("\nMAX3 Defined...\n"); 
#endif     
int res3 = MAX3(x,y,z);     
printf("\n res3 = [%d]\n", res3);
    
return 0;
}
///////////////////////////////////////////////////////////////////////////////////
