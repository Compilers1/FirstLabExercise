#include "Header.h"

int yylex(FILE* fptr, union semantic_info* sem) {
	int nextCharacter;
	char lexeme[SIZE] = {'\0'};
	unsigned int index = INIT;
	unsigned int state = INIT;
	unsigned int token = INIT;

	while ((nextCharacter = fgetc(fptr)) != EOF) {
		switch (state) {
			case 0:
				if (isalpha(nextCharacter)) {
					lexeme[index] = nextCharacter;
					index++;
					state = 1;
				}
				else if (isdigit(nextCharacter)) {
					lexeme[index] = nextCharacter;
					index++;
					state = 2;
				}
				break;
			case 1:
				token = 1;
				if (!isalnum(nextCharacter)) {
					return token;
				}
				else {
					lexeme[index] = nextCharacter;
					index++;
					sem->str = lexeme;
				}
				break;
			case 2:
				token = 2;
				if (!isdigit(nextCharacter)) {
					return token;
				}
				else {
					lexeme[index] = nextCharacter;
					index++;
					sem->num = atoi(lexeme);
				}
				break;
		}
	}
	return token;
}