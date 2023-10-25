#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

union semantic_info {
	char* str;
	int num;
};

int yylex(FILE* fptr, union semantic_info* sem);
