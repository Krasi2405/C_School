
#include <stdio.h>

void add_sorted_arrays(int size1, int size2, int * array1, int * array2, int * array3);

int main(void) {
	int size1;
	int size2;

	printf("Enter first array size: ");
	scanf("%d", &size1);

	printf("Enter second array size: ");
	scanf("%d", &size2);

	int array1[size1];
	int array2[size2];
	int array3[size1 + size2];

	for(int i = 0; i < size1; i++) {
		printf("Add first array number: ");
		scanf("%d", &array1[i]);
	}

	for(int i = 0; i < size2; i++) {
		printf("Add second array number: ");
		scanf("%d", &array2[i]);
	}

	add_sorted_arrays(size1, size2, array1, array2, array3);

	for(int i = 0; i < (size1 + size2); i++) {
		printf("\n%d", array3[i]);
	}
}

void add_sorted_arrays(int size1, int size2, int * array1, int * array2, int * array3) {
	
	int first_array_index = 0;
	int second_array_index = 0;

	for(int i = 0; i < (size1 + size2); i++) {
		if(array1[first_array_index] > array2[second_array_index]) {
			array3[i] = array2[second_array_index];
			second_array_index++;
		}
		else 
		{
			array3[i] = array1[first_array_index];
			first_array_index++;
		}

		if(first_array_index >= size1) {
			for(int j = i + 1; j < (size1 + size2); j++) {
				array3[j] = array2[second_array_index];
				second_array_index++;
			}
			break;
		}

		if(second_array_index >= size2) {
			for(int j = i + 1; j < (size1 + size2); j++) {
				array3[j] = array1[first_array_index];
				first_array_index++;
			}
			break;
		}

	}
}
