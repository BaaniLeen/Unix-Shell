//
//  my_cat.c
//  
// -n and -u
//
//  Created by Baani Leen Kaur Jolly on 19/01/18.
//

#include <string.h>
#include <stdio.h>

//cd .. handled
int main(int argc, char* argvs[])
{
    FILE *fptr;
    int i,n;
    int ch;
    if(argvs[1][0]=='-' && argvs[1][1]=='n')
    {
	    for(i =2;i<argc;i++)
	    {
		int counter=0;
        	fptr = fopen(argvs[i], "r");
        	if (fptr == NULL)
        	{
            	   printf("No such file or directory \n");
            	   break;
        	}
        	printf("%d",++counter);
		ch = fgetc(fptr);
        	while (ch != EOF)
                {
	    	  if(ch=='\n')
	    	  {
		     printf("\n%d ",(++counter));
	          }
	    	  else
	    	  {
            	     printf ("%c", ch);
            	  }
	    	 ch = fgetc(fptr);
        	}
        	fclose(fptr);
    	    }
    	    printf("\n");
    }
else if(argvs[1][0]=='-' && argvs[1][1]=='u')
{
        for(i =2;i<argc;i++)
    {
     	//int counter=0;
        fptr = fopen(argvs[i], "r");
        if (fptr == NULL)
        {
            printf("No such file or directory \n");
            break;
        }
	//printf("%d",++counter);
        ch = fgetc(fptr);
        while (ch != EOF)
        {
            printf ("%c", ch);
            ch = fgetc(fptr);
        }
	fclose(fptr);
    }
    printf("\n");

}
else
{
	for(i =1;i<argc;i++)
    {
     	//int counter=0;
        fptr = fopen(argvs[i], "r");
        if (fptr == NULL)
        {
            printf("No such file or directory \n");
            break;
        }
	//printf("%d",++counter);
        ch = fgetc(fptr);
        while (ch != EOF)
        {
            printf ("%c", ch);
            ch = fgetc(fptr);
        }
	fclose(fptr);
    }
    printf("\n");

}
return 0;
}
