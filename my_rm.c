//
//  my_rm.c
//  
//
//  Created by Baani Leen Kaur Jolly on 19/01/18.
//

#include "my_rm.h"

int main()
{
    char* file_path;
    scanf("%s",file_path);
    unlink(file_path);
    return 0;
}
