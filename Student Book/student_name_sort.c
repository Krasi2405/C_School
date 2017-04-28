// Programa koqto izvezhda spisuk s imenata na n uchenici podredeni po azbuchen red.
// max 1000 uchenika
// max 20 chara v imeto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void print_students(int num_students, int max_chars, char student_book[num_students][max_chars], int max_index);
void add_student(int num_students, int max_chars, char student_book[num_students][max_chars], int index);
void sort_students(int num_students, int max_chars, char student_book[num_students][max_chars], int max_index);
void clear();

int main(void) {
	int current_student_index = 0;
	char student_book[1000][20];
	clear();
	while(1) {

		printf("What would you like to do?\n");
		printf("Press '1' in order to add a student\n");
		printf("Press '2' in order to list students\n");
		printf("Press '3' in order to break\n");
		char input = getche();

		if(input == '1') {
			add_student(1000, 20, student_book, current_student_index);
			current_student_index++;
			sort_students(1000, 20, student_book, current_student_index);
		}
		else if(input == '2') 
		{
			print_students(1000, 20, student_book, current_student_index);
		}
		else if(input == '3') {
			return 0;
		}
	}
}

void print_students(int num_students, int max_chars, char student_book[num_students][max_chars], int max_index) {
	printf("\n");
	for(int i = 0; i < max_index; i++) {
		printf("\nStudent %d: %s", i + 1, student_book[i]);
	}
	printf("\n");
}

void add_student(int num_students, int max_chars, char student_book[num_students][max_chars], int index) {
	printf("\nEnter student name: ");
	gets(student_book[index]);
	printf("\nAdded: %s\n", student_book[index]);
}

void sort_students(int num_students, int max_chars, char student_book[num_students][max_chars], int max_index) {
	for(int i = 0; i < max_index; i++) {
		for(int j = 0; j < max_index - 1; j++) {
			// strcmp(str1, str2) - vrushta 0 ako str1 i str2 sa absolutno ednakvi
			// -1 ako str1 < str2, +1 ako str1 > str2
			int result = strcmp(student_book[j], student_book[j + 1]);
			if(result == 1) {
				char name[max_chars];
				strcpy(name, student_book[j]);
				strcpy(student_book[j], student_book[j + 1]);
				strcpy(student_book[j + 1], name);
			}
		}
	}
}

void clear() {
	system("cls");
}
