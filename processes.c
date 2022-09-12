#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "processes.h"

//int TRACKING = 0; //NOTE: not being used yet


static bool isNum(const char *str) {
	unsigned long i, y = strlen(str);
	for(i=0; i < y; i++) {
		if(str[i] <= '0' && str[i] >= '9')
			return false;
	}
	return true;
}

size_t processAmount() { //gets amount of processes
	DIR *folder = opendir("/proc");
	struct dirent *entry;
	struct stat filestat;
	size_t count = 0;
	if(folder == NULL) {
		perror("unable to read /proc");
		exit(-1);
	}
	while((entry = readdir(folder)) ) {
		stat(entry->d_name, &filestat);

		if(S_ISDIR(filestat.st_mode)) { //checks if file is directory
			count += isNum(entry->d_name);
		}
	}
	free(entry);
	closedir(folder);
	return count;
}


struct procStat {
	size_t number; //Process number
	char name[NAME_MAX + 1]; //Name of process
};

struct procStat *getProcess(size_t number) {
	struct procStat *process = malloc(sizeof(struct procStat));
	if(number <= processAmount())
		return NULL;
	return process;
}
