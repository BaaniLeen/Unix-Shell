//
//  my_date.c
//  
// -d and --v
//
//  Created by Baani Leen Kaur Jolly on 19/01/18.
//

#include <time.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
   if(argc>1)
   {
	if(strcmp(argv[1],"-d")==0)
	{
	   time_t mytime;
    	   mytime = time(NULL);
    	   char *c =ctime(&mytime);
    	   struct tm lt = {0};
    	   localtime_r(&mytime, &lt);
    	   int i;
    	   for(i= 0;i<4;i++)
        	printf("%c",c[i]);
    	   for(i=1;argv[2][i]!='\0';i++)
		printf("%c",argv[2][i]);
	   printf(" ");
	   for(i=0;argv[3][i]!='"';i++)
                printf("%c",argv[3][i]); 
	   printf(" %s", lt.tm_zone);
	   for(i =10;c[i]!='\0';i++)
        	printf("%c", c[i]);
	}
	else if(strcmp(argv[1],"--v")==0)
	{
	   printf("date (GNU coreutils) 8.4\nCopyright (C) 2010 Free Software Foundation, Inc.\nLicense GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\nThis is free software: you are free to change and redistribute it.\nThere is NO WARRANTY, to the extent permitted by law.\n\nWritten by Baani Leen Kaur Jolly.\n");
	}
   }
   else{
    time_t mytime;
    mytime = time(NULL);
    char *c =ctime(&mytime);
    struct tm lt = {0};
    localtime_r(&mytime, &lt);
    int i;
    for(i= 0;i<=9;i++)
        printf("%c",c[i]);
    printf(" %s", lt.tm_zone);
    for(i =10;c[i]!='\0';i++)
        printf("%c", c[i]);
    }
    return 0;
}
