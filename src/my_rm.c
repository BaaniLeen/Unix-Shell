//
//  my_rm.c
//  
//-i and -f implemented
//
//  Created by Baani Leen Kaur Jolly on 19/01/18.
//
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int agc, char * argv[])
{
 //   scanf("%s",file_path);

    if(argc==1) printf("Too few arguments\n");
    if(strcmp(argv[1],"-i")==0)
    {
	printf("rm: remove regular file '%s'?",argv[2]);
	char c;
	scanf("%c",&c);
	if(c=='y')
	{
	  int a = unlink(argv[1]);
	  if(a==-1)
    	  {
	    printf("rm: cannot remove ");
            printf("%s ",argv[2]);
            printf(": No such file or directory\n");
    	  }
	}
    }	
    else if(strcmp(argv[1],"-f")==0)
    {
	unlink(argv[2]);
    }
    else
    {
	int a = unlink(argv[1]);
	if(a==-1)
	{
	   printf("rm: cannot remove ");
	   printf("%s ",argv[1]);
	   printf(": No such file or directory\n");
	}
    }
    return 0;
}
