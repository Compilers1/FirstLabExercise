#include "Header.h"

int yylex(FILE* fptr, union semantic_info* sem) {
	int nextCharacter;
	char lexeme[100] = {'\0'};
	unsigned int index = 0;
	unsigned int state = 0;
	unsigned int token = 0;

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
				if (!isalnum(nextCharacter)) {
					token = 1;
					sem->str = lexeme;
				}
				else {
					lexeme[index] = nextCharacter;
					index++;
				}
				break;
			case 2:
				if (!isdigit(nextCharacter)) {
					token = 2;
					sem->num = atoi(lexeme);
				}
				else {
					lexeme[index] = nextCharacter;
					index++;
				}
				break;
		}
	}
	return token;
}