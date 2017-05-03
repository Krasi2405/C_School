// funkciq koqto opredelq dulzhinata na string.

#include <stdio.h>

int strLength(char str[]);

int main(void) {
	char str[100];
	gets(str);
	printf("String length: %d", strLength(str));
}

int strLength(char str[]) {
	int length = 0;
	while(1) {
		if(str[length] == '\0') {
			break;
		}
		length++;
	}
	// Add 1 because of terminating 0
	return length + 1;
}