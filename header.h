/* primary_header.h */
#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>

char pathgetter[10000];
char *parsing;
int ui;
char *pathcopy[1000];

void readingDir(char *kar, int Sflag, long int srvalue, char *fvalue, int tflag, char *trvalue, int eflag);

void inputForEeflag(char *argument, char *pathcopy[]);

size_t getFileSize(const char *filename, char *file);

#endif