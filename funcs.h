#pragma once
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

struct FLAGS{
	int nsecs;
	int nplaces;
	int nthreads;
	char* fifoname;
};

bool readFlags(char **argv, int argc, struct FLAGS* flags);	//reads flags and checks if they are valid or not

void printFlags(struct FLAGS* flags);	//debug purposes

double elapsedTime(time_t *start, time_t *now);	//start must have a value and now will be overwritten 
