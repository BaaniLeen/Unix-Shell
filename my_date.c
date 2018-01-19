//
//  my_date.c
//  
//
//  Created by Baani Leen Kaur Jolly on 19/01/18.
//

#include "my_date.h"
#include <time.h>
#include <stdio.h>

int main(void)
{
    time_t mytime;
    mytime = time(NULL);
    char *c =ctime(&mytime);
    struct tm lt = {0};
    localtime_r(&mytime, &lt);
    int i;
    for(i= 0;i<9;i++)
        printf("%c",c[i]);
    printf(" %s", lt.tm_zone);
    for(i =10;c[i]!='\0';i++)
        printf("%c", c[i]);
    return 0;
}
