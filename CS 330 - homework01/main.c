#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <linux/limits.h>

void usage(int argc, char** argv);
void find_file(char* dir_name, char* file_to_find);

int main(int argc, char** argv)
{
	DIR* dp;
	struct dirent* dirp;

	// check if this application is being used properly
	usage(argc, argv);

	// check to see if provided directory is accessible
	errno = 0;
	dp = opendir(argv[1]);
	if(dp == NULL) {
		switch(errno) {
			case EACCES:
				fprintf(stderr, "Permission denied\n");
				break;
			case ENOENT:
				fprintf(stderr, "Directory does not exist\n");
				break;
			case ENOTDIR:
				fprintf(stderr, "'%s' is not a directory\n", argv[1]);
				break;	
		}
	}

	// print all files in the directory
	int cnt = 0;
	while((dirp = readdir(dp)) != NULL) {
		fprintf(stdout, "%d: %s", cnt, dirp->d_name);
		if(dirp->d_type == DT_DIR) {
			printf("\t directory");
		}
		printf("\n");
		cnt++;
	}

	// close the directory 
	closedir(dp);


	// now, recursivey traverse the directory structure to find the provided
	// file name
	char* file_to_find = argv[2];
	find_file(argv[1], file_to_find);

	return 0;
}


void usage(int argc, char** argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: ./%s directory_name file_to_find\n", argv[0]);
        exit(EXIT_FAILURE);
    }
}

void find_file(char* dir_name, char* file_to_find)
{
	// TODO
    DIR* dir;
    struct dirent* entry;

    // open the directory
    dir = opendir(dir_name);
  /*
    if(dir == NULL) {
        fprintf(stderr, "Cannot open directory '%s': %s\n", dir_name, strerror(errno));
        return;
    }
    */
    // loop through all entries in the directory
    while((entry = readdir(dir)) != NULL) {
	 // if the entry is a file and its name matches the provided file name, print the full path
        /*
	snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
        // ignore '.' and '..'
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        //snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
	
        // if the entry is a directory, recursively call this function on the subdirectory
        if(entry->d_type == DT_DIR) {
            find_file(path, file_to_find);
        }
	*/
	
        // if the entry is a file and its name matches the provided file name, print the full path
	/*
	if(entry->d_type == DT_REG && strcmp(entry->d_name, file_to_find) == 0) {
            printf("Found %s in %s\n", file_to_find, dir_name);
        
	}
	*/

	if(entry->d_type == DT_DIR)
	{
		//snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
		char path[PATH_MAX];

		strcpy(path, dir_name);
        	strcat(path, "/");
        	strcat(path, entry->d_name);
        	// ignore '.' and '..'
        	if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
	       	{
            		continue;
       		}
		else
	       	{
            	find_file(path, file_to_find);
        	}
	}
	else
	{
		if(strcmp(entry->d_name, file_to_find) == 0)
		{
			printf("Found %s in %s\n", file_to_find, dir_name);
		}
       }
    }

    // close the directory
    closedir(dir);
}

