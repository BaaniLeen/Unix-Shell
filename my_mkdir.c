//
//  my_mkdir.c
//  
//
//  Created by Baani Leen Kaur Jolly on 19/01/18.
//

#include "my_mkdir.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include<string.h>

int main()
{
    int status;
    char cwd[1000],new_dir[1000];
    getcwd(cwd,sizeof(cwd));
    scanf("%s",new_dir);
    strcat(cwd,new_dir);
    status=mkdir(cwd,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    return 0;
}
