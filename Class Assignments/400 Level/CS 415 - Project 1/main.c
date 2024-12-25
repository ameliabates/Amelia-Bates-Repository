#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "string_parser.h"

void interactive();
void file(const char *filename);

void interactive()
{
	size_t  len = 0;
        int read;
	char *line = NULL;

	while(1)
	{
		fprintf(stdout, ">>> ");
      		 read = getline(&line, &len, stdin);
		
		if (read == -1)
		{
			free(line);
			line = NULL;
			break;
		}
		line[strcspn(line, "\n")] = 0;
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			line = NULL;
			break;
		}
		parseing *command = parser_string(line);
		/*
		for (int i = 0; i <command->int_commands; i++)
		{
			printf("command %d: '%s'\n", i, command->command_array[i]);
		}
		*/
		command_execution(command);	
		free_command(command);
	}
	free(line);
}

void file(const char *file)
{
	FILE *input_file = fopen(file, "r");
	FILE *output_file = fopen("output.txt", "w");
	char *line = NULL;
	size_t len = 0;
	ssize_t read_file;

	if (input_file == NULL)
	{
		fclose(input_file);
	}
	if (output_file == NULL)
	{
		fclose(output_file);
	}
	FILE *original_stdout = stdout;
	stdout = output_file;
	while ((read_file = getline(&line, &len, input_file)) != -1)
	{
		if (strcmp(line, "exit\n") == 0)
		{
			break;
		}
		parseing *command = parser_string(line);
		command_execution(command);
		free_command(command);
	}
	//fprintf(output_file, "End of file\nBye Bye!\n");
	free(line);
	stdout = original_stdout;
	fclose(input_file);
	fclose(output_file);
}	 
int main(int argc, char*argv[])
{
	if (argc == 1) 
	{
		interactive();
	}
	else if (argc == 3 && strcmp(argv[1], "-f") == 0) 
	{
		file(argv[2]);
	}
	else
	{
		fprintf(stderr, "Error: enter either interactive or file mode\n"); 
	}	
	return 0;
}
