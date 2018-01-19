//
//  my_cat.c
//  
//
//  Created by Baani Leen Kaur Jolly on 19/01/18.
//

#include "my_cat.h"
#include <string.h>

char argvs[1024][1024];

int main()
{
//    char* file_name;
    FILE *fptr;
    int i,n;
    char ch;
    scanf("%d\n",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%s",argvs[i]);
    }
    for(i =0;strcmp(argvs[i],"\0")!=0;i++)
    {
        fptr = fopen(argvs[i], "r");
        if (fptr == NULL)
        {
            printf("No such file or directory \n");
            break;
        }
        ch = fgetc(fptr);
        while (ch != EOF)
        {
            printf ("%c", ch);
            ch = fgetc(fptr);
        }
        fclose(fptr);
    }
return 0;
}
