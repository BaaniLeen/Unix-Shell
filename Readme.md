How to run it

$make
$./shell

About My_Shell

The shell basically takes an instruction as an input and then parses it based on the spaces for getting the arguments.
In case the string is equal to "exit" , we break out of the program.
In case it is "cd", we get the current working directory through getcwd() and then change the directory after concatenating the second argument of the instruction and then use chdir() to change the directory.
We append to the common path(/bin/) the name of the command, so as to search an executable for the same.
We then create a fork. in case the pid geenrated is -1, it is an error. pid 0 represents the Child Process while pid 1 represents the parent process.
The Child carries out the execvp process using the path and the arguments, while the parent thread waits for it to terminate.
