#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>
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
pid_t child[100];
int int_child = 0;
int interrupted = 0;

void signal_handler(int signal);
 
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
	
	sigset_t sigset;
	int sig;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigprocmask(SIG_BLOCK, &sigset, NULL);
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
		printf("CHILD %d WAITING IN SIGUSR1 SIGNAL...\n", getpid());
		sigwait(&sigset, &sig);
		printf("Child process %d recieved signal %s\n", getpid(), strsignal(sig));
                if (execvp(args[0], args) == -1)
                {
                        perror("error");
                        exit(0);
                }
                }
		else
		{
			child[int_child++] = forking;
		}
	  }
        fclose(file);
//	printf("Wake up all children\n");
	for (int i = 0; i < int_child; i++)
	{
		printf("Wake: Parent process %d -> child process %d\n", getpid(),child[i]); 
		kill(child[i], SIGUSR1);
	}
	sleep(1);
	//printf("Stop all child processes\n");
	for (int i = 0; i < int_child; i++)
        {
		printf("Kill: Parent process %d -> child process %d\n", getpid(),child[i]);

		kill(child[i], SIGSTOP);
        }
	sleep(1);
	//printf("resume all child processes\n");
	for (int i = 0; i < int_child; i++)
        {
		printf("Resume: Parent process %d -> child process %d\n", getpid(),child[i]);

		kill(child[i], SIGCONT);	
        }
	sleep(1);
	printf("waiting for all child processes to terminate\n");
	for (int i = 0; i < int_child; i++)
        {
		waitpid(child[i], &status, 0);
        }

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



