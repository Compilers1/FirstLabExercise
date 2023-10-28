#include "Header.h"

int main(int argc, char* argv[]) {
	FILE* fptr = NULL;
	semantic_info sem;
	int token = -1;
	int lexical_unit_counter = INIT;

	if (fopen_s(&fptr, argv[1], "r") != 0)
		exit(EXIT_FAILURE);

	while ((token = yylex(fptr, &sem)) != 0) {
		if (token == 1) {
			printf("Type: Alphanumeric, Value: %s\n", sem.str);
			lexical_unit_counter++;
		}
		else if (token == 2) {
			printf("Type: Numeric, Value: %d\n", sem.num);
			lexical_unit_counter++;
		}
		fseek(fptr, -1, SEEK_CUR);
	}
	printf("Number of lexical units: %d\n", lexical_unit_counter);

	return EXIT_SUCCESS;
}
