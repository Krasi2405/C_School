// Funkciq koqto prevrushta string vuv int

#include <stdio.h>
#include <string.h>

int stringToInt(char str[], int size, int *isNum);

int main(void) {
	char str[100];
	printf("Enter string: ");
	gets(str);

	int isNum = 0;
	int result = stringToInt(str, strlen(str), &isNum);
	if(isNum) {
		printf("Result is: %d", result);
	}
	else 
	{
		printf("Cannot be converted");
	}
	

}

int stringToInt(char str[], int size, int *isNum) {
	int number = 0;
	int multiplier = 1;
	int isNegative = 0;
	int skipFirst = 0;
	
	if(str[0] == '-') {
		isNegative = 1;
		skipFirst = 1;
	}
	else if(str[0] == '+') {
		skipFirst = 1;
	}

	for(int i = size - 1; i >= 0 + skipFirst; i--) {
		int isNumber = 0;
		int currentNum;
		int charAscii = str[i];
		if(charAscii >= 48 && charAscii <= 57) {
			isNumber = 1;
			currentNum = str[i] - 48;
		}

		if(isNumber) {
			number += currentNum * multiplier;
			multiplier *= 10;
		}
		else 
		{
			*isNum = 0;
			return -1;
		}

	}
	printf("\nchanged isNum to 1\n");
	*isNum = 1;
	if(isNegative) {
		return -number;
	}
	else
	{
		return number;
	}
}