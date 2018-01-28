/*cd takes care of invalid directory and file exception
    cd .. - Moves to the parent folder.
    cd -P - Resolves Symlinks
*/
/*echo
    echo -n - Remove endl
    echo -E - ignores escape characters and treats it as a part of the string only
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define GREEN "\x1B[32m"
#define WHITE  "\x1B[37m"
#define CYAN  "\x1B[36m"

#define HISTORY_COUNT 20

char *hist[HISTORY_COUNT];

int history(int current)
{
    int i = current;
    int hist_num = 1;
    do {
        if (hist[i]) {
            printf("%4d  %s\n", hist_num, hist[i]);
            hist_num++;
        }

        i = (i + 1) % HISTORY_COUNT;

    } while (i != current);

    return 0;
}

int main()
{
	char instr[1024],path[1024],cwd[1024],user_name[1024];
	char *argv[200],src_dir,dest_dir,final_dir;
	char common_path[1024] ; //= "/home/baani16234/Desktop/lab0/2016234/src/";
	getcwd(common_path,sizeof(common_path));
	strcat(common_path,"/");
	int argc,i,current=0;

    for (i=0; i<HISTORY_COUNT;i++)
        hist[i] = NULL;

	while(1)
	{
		/*Display the Username@My_Shell:$<Current Directory>*/
		printf("%s",GREEN);

		char *p=getenv("USER");
    	if(p!=NULL)  printf("%s@My_Shell",p);
    	else
		{
			getlogin_r(user_name,sizeof(user_name));
			printf("%s@My_Shell",user_name);
		}

		// if(getcwd(cwd,sizeof(cwd))!=NULL)
		// {
		// 	printf(":%s$", cwd);
		// }

		/*Input the Instruction*/
		printf("%s",CYAN);

		if (!fgets(instr,1024,stdin))
			break;

		int length = strlen(instr);

    /* Removing the \n from fgets */
		if(instr[length-1]=='\n')
			instr[length-1]='\0';

        free(hist[current]);

        hist[current]=strdup(instr);

        current=(current+1) % HISTORY_COUNT;

		char* token;
		token = strtok(instr," ");
		int i;
		for(i = 0; token!=NULL && i<200; i++)
		{
			argv[i]=token;
			token = strtok(NULL," ");
		}
		argv[i]=NULL;
		argc=i;

		/* Internal commands - exit, cd, pwd, echo */
        
		if (strcmp(instr,"exit")==0)
			break;
        	/*cd takes care of invalid directory and file exception
			cd .. - Moves to the parent folder.
			cd -P - Resolves Symlinks
		*/
		
		if (!strcmp(argv[0], "cd"))
		{
		if(argc==1) chdir("/Users/Jolly/");
            	else if(strcmp(argv[1],"..")==0)
        	{
          		getcwd(cwd,sizeof(cwd));
          		strcat(cwd,"/");
          		strcat(cwd,argv[1]);
//          		printf("%s\n",cwd);
          		chdir(cwd);
        	}
		else if(strcmp(argv[1],"-P")==0)
		{
			if(chdir(argv[2])==0)
				chdir(argv[2]);
			else
				printf("Invalid directory or file.\n");
		}
      		else if(chdir(argv[1])==0)
                	chdir(argv[1]);
            	else
                	printf("Invalid directory or file.\n");
            continue;
        }
        if (!strcmp(argv[0], "pwd")){
            getcwd(cwd,sizeof(cwd));
            printf("%s\n",cwd);
            continue;
        }
        if (!strcmp(argv[0], "echo"))
	{
            if(argc>1 && strcmp(argv[1],"-n")==0)
	    {
		int i;
            	for(i = 2; argv[i]!=NULL;i++)
            	{
             	  printf("%s ",argv[i]);
            	}
	    }
	    else if(argc>1 && strcmp(argv[1],"-E")==0)
	    {
            	int i;
            	for(i = 1; argv[i]!=NULL;i++)
            	{
             		printf("%s ",argv[i]);
            	}
            	printf("\n");
	    }
	    else
	    {
	    int i;
            for(i = 1; argv[i]!=NULL;i++)
            {
                printf("%s ",argv[i]);
            }
            printf("\n");
            }
	    continue;
        }
        if(!strcmp(argv[0], "history")){
            history(current);
            continue;
        }
        
    	//Make the path as "/bin/<program_name>"
    	strcpy(path,common_path);
        strcat(path,argv[0]);

    	int status; //Denotes the status of the child process

    	int pid = fork();

    	if(pid == -1)
    	{
    		printf("Can't fork a process.\n"); break;
    	}
    	else if(pid==0)
    	{
            printf("%s", path);
    		/*Done by Child Process*/
//    		execvp(path,argv);
		execv(path,argv);  
  		/*If execvp returns, it has failed. */
    		printf("Unknown command\n");
    		exit(0);
    	}
    	else
    	{
    		/*Done by Parent process*/
    		/*Waits for the child to terminate*/
    		// pid_t tpid;
    		// do
    		// {
    		// 	tpid = wait(&status);
    		// 	if(tpid!= pid) process_terminated(tpid);
    		// }
    		// while(tpid!=pid;
    		wait(NULL);
    	}
	}
}

//References : STackOverflow
  //              http://www.cs.ecu.edu/karl/4630/sum01/example1.html
