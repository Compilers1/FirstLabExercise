#include "Header.h"

int main(int argc, char* argv[]) {
	FILE* fptr = NULL;
	semantic_info sem;
	int token = -1;

	if (fopen_s(&fptr, argv[1], "r") != 0)
		exit(EXIT_FAILURE);

	while ((token = yylex(fptr, &sem)) != 0) {
		if (token == 1) {
			printf("Type: Alphanumeric, Value: %s\n", sem.str);
		}
		else if (token == 2) {
			printf("Type: Numeric, Value: %d\n", sem.num);
		}
	}

	return EXIT_SUCCESS;
}
