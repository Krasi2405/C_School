// Zadacha: Dali daden niz e validen za C identifikator
// Purviqt character trqbva da e bukva ili _
// Vuzmozhni charove sled tova - [a-z], [A-Z], _ i chisla

#include <stdio.h>
#include <string.h>

int is_valid(char string[], int length);

int main(void) {
	char str[100];
	printf("Enter string: ");
	gets(str);

	int valid = is_valid(str, strlen(str));
	if(valid) {
		printf("Valid");
	}
	else 
	{
		printf("Invalid");
	}
	
}

int is_valid(char str[], int length) {
	if(((str[0] < 'a' || str[0] > 'z') && (str[0] < 'A' || str[0] > 'Z')) && str[0] != '_') {
		return 0;
	}

	for(int i = 1; i < length; i++) {
		int first = 1;
		int second = 1;
		int third = 1;
		if(str[i] < 'a' || str[i] > 'z') {
			first = 0;
		}

		if(str[i] < 'A' || str[i] > 'Z') {
			second = 0;
		}

		if(str[i] < '0' || str[i] > '9') {
			third = 0;
		}
		if(!(first || second || third || str[i] == '_')) {
			return 0;
		}
	}
	return 1;
}