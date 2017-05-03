// Dali daden string e palindrome
#include <stdio.h>
#include <string.h>


int main(void) {
	// Patka
	char str[100];
	gets(str);
	int length = strlen(str);
	int mid = length / 2;
	char reversed_string[100];
	strcpy(reversed_string, str);
	strrev(reversed_string);
	int result = strcmp(reversed_string, str);
	if(result == 0) {
		printf("Palindrome");
	}
	else {
		printf("Not palindrome");
	}
}