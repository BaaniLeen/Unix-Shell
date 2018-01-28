# My_Shell
A simple Unix shell written in C

## Setup for Developers

1. Open the terminal and clone the repositories:
`git clone https://github.com/BaaniLeen/My_Shell.git`

1. Change the directory into the src of My_Shell:
`cd My_Shell/src/`

1. Execute the Makefile
`make`

1. Run the Shell
`./shell`

Welcome to My_Shell!


## About My_Shell

- Supports:

  ### Internal Commands
        
    1. `cd` : Change Directory
	
	Options-
	
		.. : Go to the parent directory
		-P : Cd into the absolute path

     1. `echo` : Output the given arguments
	
	Options-
	
		-n : Do not print the trailing newline
		-E : Ignores escape characters and treats it as a part of the string only

     1. `history` : Prints the history of commands typed in the current shell session
         
	 Options-
	 
              -c : Clear the history list by deleting all of the entries
	      -d offset : Delete the history entry at offset OFFSET.
              
    1. `pwd` : Print Current Working Directory
	
	Options-
	
              -L : Use PWD from environment, even if it contains symlinks
	      --help: Help display this help and exit

    1. `exit` : Exit
        
  ### External Commands - Implemented the following External Commands from Scratch:
  
    1. `ls` : List directory
    
	Options-
	
		-a : List all (including hidden) files and directories
	
		-A : List everything except . and ..

    1. `cat` : Read the following files
	
	Options-
	
		-u : Disable output buffering
		-n : Number lines in the output

    1. `rm` : Remove file
	
	Options-
	
		-f :  Force removal. Do not give any errors if encountered
		-i :  Interactive. Ask before removing any file
	
    1. `date` : Show the date in various formats
	
	Options-
	
		-d "Jan 9" : Print date from the given string
		--v : Give version output
	
    1. `mkdir` : Make a directory
	
	Options-
	
		-v : verbose directory making (tell whatever mkdir is currently doing)
		--help : print help           
