//
//  my_mkdir.c
// -v and --help 
//
//  Created by Baani Leen Kaur Jolly on 19/01/18.
//

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
    if(argv[1][0]=='-' && argv[1][1]=='v')
    {
    int status;
    char cwd[1000];
    getcwd(cwd,sizeof(cwd));
    strcat(cwd,"/");
    strcat(cwd,argv[2]);
    status=mkdir(cwd,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    printf("mkdir: created directory '%s'\n",argv[2]);    
    }
    else if(strcmp(argv[1],"--help")==0)
    {
	printf("Usage: mkdir [OPTION]... DIRECTORY...\nCreate the DIRECTORY(ies), if they do not already exist.\n\nMandatory arguments to long options are mandatory for short options too.\n-m, --mode=MODE   set file mode (as in chmod), not a=rwx - umask\n-p, --parents     no error if existing, make parent directories as needed\n -v, --verbose     print a message for each created directory\n -Z, --context=CTX  set the SELinux security context of each created\ndirectory to CTX\n --help     display this help and exit\n--version  output version information and exit\n\nReport mkdir bugs to bug-coreutils@gnu.org\nGNU coreutils home page: <http://www.gnu.org/software/coreutils/>\nGeneral help using GNU software: <http://www.gnu.org/gethelp/>\nReport mkdir translation bugs to <http://translationproject.org/team/>\nFor complete documentation, run: info coreutils 'mkdir invocation'\n");    
    }
    else
    {
    for(int i= 1;i<argc;i++)
    {
    int status;
    char cwd[1000];
    getcwd(cwd,sizeof(cwd));
    strcat(cwd,"/");
    strcat(cwd,argv[i]);
    status=mkdir(cwd,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }
    }
    return 0;
}
