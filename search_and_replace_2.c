#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * replace(char str[], char substr[], char replace[]);

int main(void) {
	char str[100];
	printf("Enter string: ");
	gets(str);

	char substr1[10];
	printf("Enter substring to look for: ");
	gets(substr1);

	char substr2[10];
	printf("Enter replacing string: ");
	gets(substr2);

	char * replaced = replace(str, substr1, substr2);
	puts(replaced);
}

char * replace(char str[], char substr1[], char substr2[]) {

	char * char_index = strstr(str, substr1);
	int found_index = char_index - str;
	printf("\n\nFound index: %d\n", found_index);

	char * end_str = (char *)malloc(sizeof(char) * strlen(str) + strlen(substr2));

	// First part
	int str_index = 0;
	int i;
	for(i = 0; i < found_index; i++) {
		end_str[str_index] = str[i];
		str_index++;
	}

	// Replaced part
	for(i = 0; i < strlen(substr2); i++) {
		end_str[str_index] = substr2[i];
		str_index++;
	}

	// Last part
	for(i = found_index + strlen(substr1); i < strlen(str); i++) {
		end_str[str_index] = str[i];
		str_index++;
	}
	end_str[str_index] = '\0';

	return end_str;
}