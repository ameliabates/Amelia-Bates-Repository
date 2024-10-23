#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_parser.h"
#include "command.h"
#include <ctype.h>

typedef struct {
	char *para[20];
	int int_para;
} parseing_t; 

char *trim_white_space(char *str)
{
	while (isspace((unsigned char)*str)) str++;
	char *end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end)) end--;
	*(end + 1) = '\0';
	return str;
	//I hate c!
}
parseing *parser_string(char *input)
{
	parseing *commands = malloc(sizeof(parseing));
	commands->int_commands = 0;
	char *dupe = strtok(input, ";");

	while(dupe != NULL)
	{
		commands->command_array[commands->int_commands++]= strdup(trim_white_space(dupe));	
	dupe = strtok(NULL, ";");
	}
	return commands;
}
parseing_t parser_command(char *input)
{
	parseing_t parameters;
	parameters.int_para = 0;

	char *para = strtok(input, " ");
	while (para != NULL )
	{
		parameters.para[parameters.int_para++] = strdup(para);
		para = strtok(NULL, " ");
	}
	return parameters;
}

void free_para(parseing_t *cmd)
{
	for (int i = 0; i < cmd->int_para; i++)
	{
		free(cmd->para[i]);
	}
} 
void command_execution(parseing *commands)
{
	for (int i = 0; i < commands->int_commands; i++)
	{
		parseing_t cmd = parser_command(commands->command_array[i]);
		
		if (cmd.int_para == 0)
		{
			continue;
		} 
		if (strcmp(cmd.para[0], "ls") == 0)
		{
			if (cmd.int_para == 1)
			{
				listDir();
			}
			else{
				fprintf(stderr, "Error! Unsupported parameters for command: %s\n", cmd.para[1]);
			}
		}
		else if (strcmp(cmd.para[0], "mkdir") == 0)
		{
			if (cmd.int_para == 2)
			{
				makeDir(cmd.para[1]);
			}
			else
			{
				fprintf(stderr, "Error! Unsupported parameters.\n");
			}
		}
		else if (strcmp(cmd.para[0], "pwd") == 0)
		{
			if (cmd.int_para == 1)
                        {
			showCurrentDir();
			}
			else
                        {
			fprintf(stderr, "Error! Unsupported parameters.\n");
                        }
		}
		else if (strcmp(cmd.para[0], "cd") == 0)
		{
			if (cmd.int_para == 2)
                        {
			changeDir(cmd.para[1]);
			}
			else
                        {
			fprintf(stderr, "Error! Unsupported parameters.\n");
                        }
		}
		else if (strcmp(cmd.para[0], "cp") == 0)
		{
			if (cmd.int_para == 3)
                        {
			copyFile(cmd.para[1], cmd.para[2]);
			}
			else
                        {
			 fprintf(stderr, "Error! Unsupported parameters.\n");
                        }

		}
		else if (strcmp(cmd.para[0], "mv") == 0)
		{
			if (cmd.int_para == 3)
                        {
			moveFile(cmd.para[1], cmd.para[2]);
			}
			else
                        {
			 fprintf(stderr, "Error! Unsupported parameters.\n");
                        }

		}
		else if (strcmp(cmd.para[0], "rm") == 0)
		{
			if (cmd.int_para == 2)
                        {
			deleteFile(cmd.para[1]);
			}
			else
                        {
			 fprintf(stderr, "Error! Unsupported parameters.\n");
                        }

		}
		else if (strcmp(cmd.para[0], "cat") == 0)
		{
			if (cmd.int_para == 2)
                        {
			displayFile(cmd.para[1]);
			}
			else
                        {
			 fprintf(stderr, "Error! Unsupported parameters.\n");
                        }

		}
		else
		{
			fprintf(stdout, "Error! Unrecognized command: %s\n", cmd.para[0]);
		}
	free_para(&cmd);
	}
}

	
void free_command(parseing *commands)
{
	for (int i = 0; i < commands->int_commands; i++)
	{
		free(commands->command_array[i]);
	}
	free(commands);
}
