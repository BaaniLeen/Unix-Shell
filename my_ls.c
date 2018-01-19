//
//  my_ls.c
//  
//
//  Created by Baani Leen Kaur Jolly on 19/01/18.
//

#include "my_ls.h"

#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include<sys/stat.h>

extern  int alphasort();

int main()
{
    //Ref : man page of scandir
    struct dirent **namelist;
    int n,initial;
    
    n = scandir(".", &namelist, 0, alphasort);
    initial=n;
    if (n < 0)
        perror("scandir");
    else {
        while (n--) {
            initial++;
            if((namelist[n]->d_name)[0]!='.')
            {
                printf("%s    ", namelist[n]->d_name);
                free(namelist[n]);
            }
//            else if ()//IF LS -a
//            {
//                printf("%s    ", namelist[n]->d_name);
//                free(namelist[n]);
//            }
        }
        free(namelist);
    }
    printf("\n");
    return 0;
}
