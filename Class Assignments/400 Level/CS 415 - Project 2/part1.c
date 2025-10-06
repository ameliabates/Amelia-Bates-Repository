#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void paresing(char *line, char **args)
{
	int i = 0;
	char *command = strtok(line, " \n");
	while (command!= NULL)
	{
		args[i++] = command;
		command = strtok(NULL, " \n");
	}
	args[i] = NULL;
}

void execute(const char *filename)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		perror("File unable to be opened");
		exit(EXIT_FAILURE);
	}

	char line[260];
	pid_t forking;
	int status;
	//int int_child = 0;
	//printf("Parent process: %d\n", getpid());
	while (fgets(line, sizeof(line), file) != NULL)
	{
		char *args[10];
		paresing(line, args);
		
		forking = fork();
		if (forking < 0)
		{
			perror("fork faulure");
			exit(0);
		}
		else if (forking == 0)
		{
		//	int_child++;
		//	printf("Child proc: %d, with id: %d\n", int_child, getpid()); 	
		if (execvp(args[0], args) == -1)
		{
			perror("error");
			exit(0);
		}
		}
	}
	while(wait(&status) >0);
	fclose(file);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
	printf("Wrong number of arguments");
	exit(0);
	}
	execute(argv[1]);
	printf("Completed all processes\n");
	return 0;
}
