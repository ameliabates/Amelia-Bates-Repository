Name
Psuedo-Shell Project 1


Description
This project created a pseudo-shell that operates in both file and interactive mode to execute a 8 UNIX system commands. These commands are: ls, pwd, mkdir, cd, cp, mv, rm, and cat. 


Commands
* ls: lists the contents of the directory
* pwd: prints the address of the current directory
* mkdir: creates a new directory
* cd: changes the current directory to the destination directory
* cp: copies files from one address to another
* mv: moves files
* rm: deletes a file
* cat: displays the contents of a file


File Structure
* main.c: the programs entry point and manages both interactive and file mode
* command.c: the functions that handle each of the shell commands
* command.h: the header file which contains the function declarations for the shell commands
* string_parser.c: parses the information that the user inputted into singular commands. Contains the functions for execution and freeing these commands. 
* string_parser.h: the header file which contains the function declaration for command parsing
* Makefile: compiles the project


Compilation
        Interactive Mode
* make  <~ to compile the project
* ./psuedo-shell <~ run the program without arguments
* >>> ls  <~ enter any UNIX command
* >>> exit <~ when you are done quit the program by typing “exit”
        File Mode
* make  <~ to compile the project
* ./psuedo-shell -f ./input.txt <~ run the program with an input file
* cat output.txt <~ view the output.txt


Roadmap
        In the future, I would like to expand this project to include more UNIX commands and the ability to handle more errors.