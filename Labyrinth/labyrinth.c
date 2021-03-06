#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void create_labyrinth_automatically(int rows, int collumns, int labyrinth[rows][collumns]);
void create_passable_labyrinth_automatically(int rows, int collumns, int labyrinth[rows][collumns]);
void create_labyrinth_manually(int rows, int collumns, int labyrinth[rows][collumns]);
void create_labyrinth(int rows, int collumns, int labyrinth[rows][collumns]);
void print_labyrinth(int rows, int collumns, int labyrinth[rows][collumns]);
void print_path(int rows, int collumns, int path[rows * collumns][2]);
int find_path(int rows, int collumns, int labyrinth[rows][collumns], int checked_tiles[rows][collumns],
			  int path[rows * collumns][2], int current_x, int current_y, int path_num);
int path_exists(int rows, int collumns, int labyrinth[rows][collumns], int checked_tiles[rows][collumns],
			    int current_x, int current_y);
void create_empty_matrix(int rows, int collumns, int matrix[rows][collumns], int number);
void clear();
// LEGEND:
// Unpassable terrain: 0
// Passable terrain: 1
// Player: 2

int main(void) {
	int rows, collumns;
	

	printf("Enter rows: ");
	scanf("%d", &rows);
	printf("Enter collumns: ");
	scanf("%d", &collumns);

	int checked_tiles[rows][collumns];
	int path[rows * collumns][2];
	create_empty_matrix(rows, collumns, checked_tiles, 0);
	create_empty_matrix(rows * collumns, 2, path, -1);
	checked_tiles[0][0] = 1;
	
	int labyrinth[rows][collumns];
	create_labyrinth(rows, collumns, labyrinth);
	clear();
	print_labyrinth(rows, collumns, labyrinth);

	if(!find_path(rows, collumns, labyrinth, checked_tiles, path, 0, 0, 0)) {
		printf("No path exists!");
	}
	else 
	{
		print_path(rows, collumns, path);
	}
}

void create_empty_matrix(int rows, int collumns, int matrix[rows][collumns], int number) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < collumns; j++) {
			matrix[i][j] = number;
		}
	}
}

void create_labyrinth_automatically(int rows, int collumns, int labyrinth[rows][collumns]) {
	srand(time(NULL));
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < collumns; j++) {
			int r = 1;
			r = rand() % 2;
			labyrinth[i][j] = r;
		}
	}
	labyrinth[0][0] = 1;
	labyrinth[rows - 1][collumns - 1] = 1;
}

void create_passable_labyrinth_automatically(int rows, int collumns, int labyrinth[rows][collumns]) {
	
	int checked_tiles[rows][collumns];
	do 
	{
		create_empty_matrix(rows, collumns, labyrinth, 0);
		create_empty_matrix(rows, collumns, checked_tiles, 0);
		checked_tiles[0][0] == 1;
		srand(time(NULL));
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < collumns; j++) {
				int r = 1;
				r = rand() % 2;
				labyrinth[i][j] = r;
			}
		}
		labyrinth[0][0] = 1;
		labyrinth[rows - 1][collumns - 1] = 1;
	} while(!path_exists(rows, collumns, labyrinth, checked_tiles, 0, 0));
}

void create_labyrinth_manually(int rows, int collumns, int labyrinth[rows][collumns]) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < collumns;) {
			char input = getche();
			if(input == '0') {
				labyrinth[i][j] = 0;
				j++;
			}
			else if(input == '1') 
			{
				labyrinth[i][j] = 1;
				j++;
			}
		}
		printf("\n");
	}
}

void create_labyrinth(int rows, int collumns, int labyrinth[rows][collumns]) {
	int creation_method;
	while(1) {
		printf("Which method would you like to choose for creating the labyrinth?\n");
		printf("Press '1' in order to create a totally random labyrinth\n");
		printf("Press '2' in order to create a random passable labyrinth(Might take a while)\n");
		printf("Press '3' in order to enter the labyrinth manually\n");
		scanf("%d", &creation_method);
		if(creation_method == 1) {
			create_labyrinth_automatically(rows, collumns, labyrinth);
		}
		else if(creation_method == 2) 
		{
			create_passable_labyrinth_automatically(rows, collumns, labyrinth);
		}
		else if(creation_method == 3) 
		{
			create_labyrinth_manually(rows, collumns, labyrinth);
		}
		else 
		{
			printf("Invalid method chosen. Please try again.");
			continue;
		}
		break;
	}
}

void print_labyrinth(int rows, int collumns, int labyrinth[rows][collumns]) {

	printf("\nCollumns: ");
	for(int j = 0; j < collumns; j++) {
		printf("%d ", j + 1);
	}

	printf("\n\n");
	for(int i = 0; i < rows; i++) {
		printf("Row %d:    ", i + 1);
		for(int j = 0; j < collumns; j++) {
			printf("%d ", labyrinth[i][j]);
		}
		printf("\n");
	}
}

void print_path(int rows, int collumns, int path[rows * collumns][2]) {
	int path_num = 1;
	printf("Path: \n");
	for(int i = 0; i < rows * collumns; i++) {
		if(path[i][0] != -1) {
			printf("%d. X: %d | Y: %d\n", path_num, path[i][0] + 1, path[i][1] + 1);
			path_num++;
		}
	}
}

int find_path(int rows, int collumns, int labyrinth[rows][collumns], int checked_tiles[rows][collumns],
			  int path[rows * collumns][2], int current_x, int current_y, int path_num) {

	int starting_path_num = path_num;
	int path1 = 0;
	int path2 = 0;
	int path3 = 0;
	int path4 = 0;

	// Return 1 if reached the end.
	if(current_x == rows - 1 && current_y == collumns - 1) {
		path[path_num][0] = current_x;
		path[path_num][1] = current_y;
		return 1;
	}

	// Checks if position: 
	// 1. is out ouf array bounds
	// 2. is available(is 1 in labyrinth array)
	// 3. isnt already checked
	// If at least one of the combinations is true run another instance of function with other parameters
	// Else return 0
	
	if(current_x - 1 >= 0 && labyrinth[current_x - 1][current_y] && !checked_tiles[current_x - 1][current_y]) {
		checked_tiles[current_x - 1][current_y] = 1;
		path1 = find_path(rows, collumns, labyrinth, checked_tiles, path, current_x - 1, current_y, ++path_num);
	}

	if(current_y - 1 >= 0 && labyrinth[current_x][current_y - 1] && !checked_tiles[current_x][current_y - 1]) {
		checked_tiles[current_x][current_y - 1] = 1;
		path2 = find_path(rows, collumns, labyrinth, checked_tiles, path, current_x, current_y - 1, ++path_num);
	}

	if(current_x + 1 < rows && labyrinth[current_x + 1][current_y] && !checked_tiles[current_x + 1][current_y]) {
		checked_tiles[current_x + 1][current_y] = 1;
		path3 = find_path(rows, collumns, labyrinth, checked_tiles, path, current_x + 1, current_y, ++path_num);
	}

	if(current_y + 1 < collumns && labyrinth[current_x][current_y + 1] && !checked_tiles[current_x][current_y + 1]) {
		checked_tiles[current_x][current_y + 1] = 1;
		path4 = find_path(rows, collumns, labyrinth, checked_tiles, path, current_x, current_y + 1, ++path_num);
	}

	if(path1 || path2 || path3 || path4) {
		path[starting_path_num][0] = current_x;
		path[starting_path_num][1] = current_y;
		return 1;
	}
	else 
	{
		return 0;
	}
}

int path_exists(int rows, int collumns, int labyrinth[rows][collumns], int checked_tiles[rows][collumns],
			    int current_x, int current_y) {
	int path1 = 0;
	int path2 = 0;
	int path3 = 0;
	int path4 = 0;

	// Return 1 if reached the end.
	if(current_x == rows - 1 && current_y == collumns - 1) {
		return 1;
	}

	// Checks if position: 
	// 1. is out ouf array bounds
	// 2. is available(is 1 in labyrinth array)
	// 3. isnt already checked
	// If at least one of the combinations is true run another instance of function with other parameters
	// Else return 0
	
	if(current_x - 1 >= 0 && labyrinth[current_x - 1][current_y] && !checked_tiles[current_x - 1][current_y]) {
		checked_tiles[current_x - 1][current_y] = 1;
		path1 = path_exists(rows, collumns, labyrinth, checked_tiles, current_x - 1, current_y);
	}

	if(current_y - 1 >= 0 && labyrinth[current_x][current_y - 1] && !checked_tiles[current_x][current_y - 1]) {
		checked_tiles[current_x][current_y - 1] = 1;
		path2 = path_exists(rows, collumns, labyrinth, checked_tiles, current_x, current_y - 1);
	}

	if(current_x + 1 < rows && labyrinth[current_x + 1][current_y] && !checked_tiles[current_x + 1][current_y]) {
		checked_tiles[current_x + 1][current_y] = 1;
		path3 = path_exists(rows, collumns, labyrinth, checked_tiles, current_x + 1, current_y);
	}

	if(current_y + 1 < collumns && labyrinth[current_x][current_y + 1] && !checked_tiles[current_x][current_y + 1]) {
		checked_tiles[current_x][current_y + 1] = 1;
		path4 = path_exists(rows, collumns, labyrinth, checked_tiles, current_x, current_y + 1);
	}

	if(path1 || path2 || path3 || path4) {
		return 1;
	}
	else 
	{
		return 0;
	}
}


void clear() {
	system("cls");
}