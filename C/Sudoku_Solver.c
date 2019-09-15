#include <stdio.h>

#define N 9 //the grid is 9X9
#define UNASSIGNED 0 //'0' value means that the cell is empty.

//Sudoku Solver 

//Checking if the number exist in the row
int exist_row(int grid[N][N], int row, int num){
	for (int col = 0; col < 9; col++) {
		if (grid[row][col] == num) {
			return 1;
		}
	}
	return 0;
}
//Checking if the number exist in the column.
int exist_col(int grid[N][N], int col, int num) {
	for (int row = 0; row < 9; row++) {
		if (grid[row][col] == num) {
			return 1;
		}
	}
	return 0;
}

//Checking if the number exist in the 3X3 box.
int exist_box(int grid[N][N], int startRow, int startCol, int num) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (grid[row + startRow][col + startCol] == num) {
				return 1;
			}
		}
	}
	return 0;
}

//it is safe to put in a number if the number doesn't already exist in: 1.box 2.row 3.column.
int is_safe_num(int grid[N][N], int row, int col, int num) {
	return !exist_row(grid, row, num)
			&& !exist_col(grid, col, num)
			&& !exist_box(grid, row - (row % 3), col - (col %3), num);
}

//fins unassigned spots with the value of '0'
int find_unassigned(int grid[N][N], int *row, int *col) {
	for (*row = 0; *row < N; (*row)++) {
		for (*col = 0; *col < N; (*col)++) {
			if (grid[*row][*col] == 0) {
				return 1;
			}
		}
	}
	return 0;
}

//solves the sudoko with the by the following method
int solve(int grid[N][N]) {

	int row = 0;
	int col = 0;

    //if no unassigned values(0) then sudoko is complete
	if (!find_unassigned(grid, &row, &col)){
		return 1;
	}

    //running a loop that uses the "is safe" function to determine if the number can be placed there.
	for (int num = 1; num <= N; num++ ) {

		if (is_safe_num(grid, row, col, num))
        {
            //places a number in a specific spot in the grid
			grid[row][col] = num;

            //returns if success.
			if (solve(grid)) {
				return 1;
			}

			grid[row][col] = UNASSIGNED;
		}
	}
    //the part that triggers the backtracking.
	return 0;
}

//prints the grid, and separates the 3X3 boxes.
void print_grid(int grid[N][N]) {
	for (int row = 0; row < N; row++) {
            if(row%3 == 0){printf("++++++++++++++++++++++\n");}
		for (int col = 0; col < N; col++)
        {
            if(col%3 == 0){printf("|");}
			printf("%2d", grid[row][col]);
		}
		printf("|\n");
	}
}

int main() {

//Driver Program to see if works
//The sudoko grid. '0' means empty cell
	int grid[N][N] = {{0,0,0, 0,0,3, 2,9,0},
			 {0,8,6, 5,0,0, 0,0,0},
			 {0,2,0, 0,0,1, 0,0,0},
			 {0,0,3, 7,0,5, 1,0,0},
			 {9,0,0, 0,0,0, 0,0,8},
			 {0,0,2, 9,0,8, 3,0,0},
			 {0,0,0, 4,0,0, 0,8,0},
			 {0,4,7, 1,0,0, 0,0,0}};

	if (solve(grid))
    {
		print_grid(grid);
	}
    else
    {
		printf("no solution for this sudoko...fuck..");
	}

	return 0;
}
