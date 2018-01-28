//
//  my_ls.c
//
//  Handles ls -a and ls -A
//
//  Created by Baani Leen Kaur Jolly on 19/01/18.
//

#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include<sys/stat.h>
#include <string.h>
#include <stdio.h>

extern  int alphasort();

int main(int argc, char *argv[]){
    //Ref : man page of scandir

	if(argc>1)
	{
	if(!strcmp(argv[1],"-a"))
	{
           struct dirent **namelist;
           int n;

           n = scandir(".", &namelist, 0, alphasort);
           if (n < 0)
               perror("scandir");
           else 
	   {
               while (n--) 
		{
                   printf("%s    ", namelist[n]->d_name);
                   free(namelist[n]);
               }
               free(namelist);
		printf("\n");
           }
	}
	else if(!strcmp(argv[1],"-A"))
	{
	   struct dirent **namelist;
           int n;

           n = scandir(".", &namelist, 0, alphasort);
           if (n < 0)
               perror("scandir");
           else  
           {
               while (n--)  
                {
           	if(strcmp((namelist[n]->d_name),".")!=0)
		{
			if(strcmp((namelist[n]->d_name),"..")!=0)
	           	{
				printf("%s    ", namelist[n]->d_name);
                   		free(namelist[n]);
			}
		}
               }
               free(namelist);
                printf("\n");
           }
	}
	}
	else{	
    		struct dirent **namelist;
    		int n,initial;
    
    		n = scandir(".", &namelist, 0, alphasort);
    		initial=n;
    		if (n < 0)
        		perror("scandir");
   		else 
		{
        		while (n--) 
			{
            		initial++;
            		if((namelist[n]->d_name)[0]!='.')
            		{
                		printf("%s    ", namelist[n]->d_name);
                		free(namelist[n]);
            		}
        		}
        		free(namelist);
    		}
    		printf("\n");
		}
    		return 0;
	}

