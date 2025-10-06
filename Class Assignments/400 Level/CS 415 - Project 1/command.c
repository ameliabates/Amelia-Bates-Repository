#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
void listDir()
{
	//ls command
	DIR *dir;
	struct dirent *entry_point;

	dir = opendir(".");
	if (dir == NULL)
	{
		perror("Error: ls");
	}
	while ((entry_point = readdir(dir)) != NULL)
	{
			fprintf( stdout, entry_point->d_name);
			fprintf(stdout, " "); 
	}
	fprintf(stdout, "\n");
	closedir(dir);
}

void makeDir( char *dirName)
{
	int error_reading;
	struct stat st = {0};

	if (stat(dirName, &st) == -1)
	{
	error_reading = mkdir(dirName, 0755);
	if (error_reading == 1)
	{
		perror("mkdir");
	}
	}
	else
	{
		fprintf(stdout, "Directory already exists!\n");
	}
}

void showCurrentDir()
{
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		fprintf(stdout, cwd);
		fprintf(stdout, "\n"); 
	}
	else
	{
		perror("Error: pwd");
	}
}

void changeDir(char *dirName)
{
	if (chdir(dirName) ==0)
	{
	}
	else
	{
		perror("Error: cd");
	}
}

void copyFile(char *sourcePath, char *destinationPath)
{
	FILE *source = fopen(sourcePath, "rb");
	char buffer[1024];
	size_t lines;
	struct stat dst_stat;
	
	if (source <0)
	{
		perror("Error: source in cp");
	}
	//had to find similar solution online. Couldn't figure out/ but not copied
	if (stat(destinationPath, &dst_stat) == 0 && S_ISDIR(dst_stat.st_mode))
	{
		char *source_name = basename((char *)sourcePath);
		char destination[1024];
		snprintf(destination, sizeof(destination), "%s/%s", destinationPath, source_name);
		destinationPath = destination;
	}
	
	FILE *putItHere = fopen(destinationPath, "wb");
	if (putItHere < 0)
	{
		perror("Error: destination file in cp");
	}
	while((lines = fread(buffer, 1, sizeof(buffer), source)) >0)
	{
		fwrite(buffer, 1, lines, putItHere);
	}
	fclose(source);
	fclose(putItHere);
}
void moveFile(char *sourcePath, char *destinationPath)
{
	/*
	rename(sourcePath, destinationPath);
	*/

	struct stat dst_stat;
	if (stat(destinationPath, &dst_stat) == 0 && S_ISDIR(dst_stat.st_mode))
        {
                char *source_name = basename((char *)sourcePath);
                char destination[1024];
                snprintf(destination, sizeof(destination), "%s/%s", destinationPath, source_name);
                destinationPath = destination;
        }
	if (rename(sourcePath, destinationPath) != 0)
	{
		perror("Error: rm");
	}	
}

void deleteFile(char *filename)
{
	if (unlink(filename)== 0)
	{
	}
	else
	{
		perror("Error: rm");
	}
}

void displayFile(char *filename)
{
	FILE *file;
	char buffer[1024];
	size_t read_file;

	file = fopen(filename, "r" );
	if (file < 0)
	{
		perror("Error: cat");
	}	
	while ((read_file  = fread(buffer, 1, sizeof(buffer), file)) >0)
	{
		fwrite(buffer, 1, read_file, stdout);
	}
	//fwrite(" ", sizeof(char), 1, stdout);
	fclose(file);
}
