#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define INIT 0
#define SIZE 100

union semantic_info {
	char* str;
	int num;
};

int yylex(FILE* fptr, union semantic_info* sem);
