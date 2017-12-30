#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define GREEN "\x1B[32m"
#define WHITE  "\x1B[37m"
#define CYAN  "\x1B[36m"

int main()
{
	char instr[1024],path[30],cwd[1024],user_name[1024];
	char *argv[200],src_dir,dest_dir,final_dir;
	char *common_path = "/bin/";
	int argc;

	// system("color 0");

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


		if(getcwd(cwd,sizeof(cwd))!=NULL)
		{
			printf(":%s$", cwd);
		}	

		/*Input the Instruction*/
		printf("%s",CYAN);
		
		if (!fgets(instr,1024,stdin))
			break;

		int length = strlen(instr);
		if(instr[length-1]=='\n')
			instr[length-1]='\0';

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

		/*If the instruction is exit or cd*/
		if (strcmp(instr,"exit")==0)
			break;
		if (!strcmp(argv[0], "cd")){
			strcat(cwd,"/");
			strcat(cwd,argv[1]);
            chdir(cwd);
            continue;
        }

    	//Make the path as "/bin/<program_name>"
    	strcpy(path,common_path);
    	strcat(path,argv[0]);		//add the location of the program
	
    	int status; //Denotes the sttaus of the child process

    	int pid = fork();

    	if(pid == -1)
    	{ 
    		printf("Can't fork a process.\n"); break; 
    	}
    	else if(pid==0)
    	{
    		/*Done by Child Process*/
    		execvp(path,argv);
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
