#include<stdio.h>

/*
int main()
{
char str[100];

printf("Enter the String : ");
scanf("%[^\n]s",str);  // Accept String

printf("String is : %s ",str);
int i = 0;
getchar();
}
*/


int main()
{
int i = 0;
char name[2000]; 
int lines = 1;
printf("\nThe number of characters is: "); 

while((name[i] = getchar())!='@')
        
        i++;
        
        printf("%d \n", i);
               
        //printf("%s  \n",name);
        //if ((name[i] = getchar()) =' ')
            //printf("End \n");
//printf("%s  \n",name);

int j = 0;
int spaces = 0;
for (j=0;name[j];j++)
    if (name[j] == ' ')
      spaces++;
    else if (name[j] == '\n')
      lines++;

printf("Spaces %d  lines  %d ",spaces, lines);  
  

          //getchar();
          
return 0;
}

