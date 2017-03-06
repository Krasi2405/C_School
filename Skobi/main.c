#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <conio.h>

int MAX_ITEMS = 250;

void clear() {
	system("cls");
}

void copy(int copy_from[], int copy_to[], int size) {
	for(int i = 0; i < size; i++) {
		copy_to[i] = copy_from[i];
	}
}

int main(void) {

	clear();

	char input_array[MAX_ITEMS];
	int current_index = 0;
	int balance = 0;
	int is_balanced = 1;

	while(current_index < MAX_ITEMS) {
		char input = getche();
		if(input == 13 ) {
			if(balance != 0) {
				is_balanced = 0;
			}
			break;
		}

		if(input == '(') {
			balance++;
		}
		else if(input == ')') {
			balance--;
		}

		if(balance < 0) {
			is_balanced = 0;
		}

		input_array[current_index] = input;
		current_index++;
	}

	clear();
	if(is_balanced) {
		printf("Array is balanced.");
		int size = current_index;

		int brackets_array[size / 2][2];
		
		int current_bracket = 0;

		for(int i = 0; i < size - 1; i++) {
			if(input_array[i] == '(') {
				balance = 0;
				for(int a = i + 1; a < size; a++) {
					if(input_array[a] == '(') {
						balance++;
					}
					else if(input_array[a] == ')') {
						balance--;
					}

					if(balance < 0) {
						brackets_array[current_bracket][0] = i + 1;
						brackets_array[current_bracket][1] = a + 1;
						current_bracket++;
						break;
					}
				}
			}
		}
		printf("Entry array: \n");
		for(int i = 0; i < size; i++) {
			printf("%c", input_array[i]);
		}

		for(int i = 0; i < (size / 2); i++) {
			printf("\nOpening: %d\tClosing: %d", brackets_array[i][0], brackets_array[i][1]);
		}
		return 0;
	}
	else {
		printf("Array is unbalanced.");
		return 0;
	}
}