#include <iostream>

using namespace std;

#define MAXN 9

bool UsedInRow(int grid[MAXN][MAXN], int row, int num); //check if used in row
bool UsedInCol(int grid[MAXN][MAXN], int col, int num); //check if used in col
bool UsedInBox(int grid[MAXN][MAXN], int boxStartRow, int boxStartCol, int num); //check if used in box
bool NoConflicts(int grid[MAXN][MAXN], int row, int col, int num); //check if it is ok to place the number
bool FindUnassignedLocation(int grid[MAXN][MAXN], int &row, int &col); //find next empty row and col to be filled
void PrintGrid(int grid[MAXN][MAXN]); //print board

bool SolveSudoku(int grid[MAXN][MAXN]){
	int row = 0, col = 0; // init row and col
	
	if(!FindUnassignedLocation(grid, row, col)) return true;
		
	for(int num = 1; num <= 9; num++){
		if(NoConflicts(grid, row, col, num)){
			grid[row][col] = num;
			PrintGrid(grid); cout << endl;
			if(SolveSudoku(grid)) return true;
			grid[row][col] = 0;
		}
	}
	return false;
}

bool FindUnassignedLocation(int grid[MAXN][MAXN], int &row, int &col){
	for(row = 0; row < MAXN; row++){
		for(col = 0; col < MAXN; col++){
			if(grid[row][col] == 0) return true;
		}	
	}
	return false;
}

bool NoConflicts(int grid[MAXN][MAXN], int row, int col, int num){
	return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 3, col - col % 3, num);
}

bool UsedInRow(int grid[MAXN][MAXN], int row, int num){
	for(int col = 0; col < MAXN; col++){
		if(grid[row][col] == num) return true;
	}
	return false;
}

bool UsedInCol(int grid[MAXN][MAXN], int col, int num){
	for(int row = 0; row < MAXN; row++){
		if(grid[row][col] == num) return true;
	}
	return false;
}

bool UsedInBox(int grid[MAXN][MAXN], int boxStartRow, int boxStartCol, int num){
	for(int col = 0; col < 3; col++){
		for(int row = 0; row < 3; row++){
			if(grid[boxStartRow+row][boxStartCol+col] == num) return true;	
		}
	}
	return false;
}

void PrintGrid(int grid[MAXN][MAXN]){
	for(int i = 0; i < MAXN; i++){
		for(int j = 0; j < MAXN; j++){
			if(grid[i][j] == 0) cout << "_ ";
			else cout << grid[i][j] << " ";
		} cout << endl;
	}
}

int main(){
	int grid[MAXN][MAXN] = 
	{
	{0, 0, 3, 0, 5, 6, 7, 8, 9},
	{4, 5, 6, 0, 8, 0, 0, 2, 3},
	{7, 0, 9, 0, 2, 3, 4, 5, 6},
	{2, 3, 0, 5, 0, 7, 0, 9, 0},
	{5, 6, 7, 8, 9, 0, 0, 3, 4},
	{8, 9, 0, 0, 3, 4, 0, 6, 7},
	{3, 0, 0, 0, 7, 0, 0, 0, 2},
	{6, 7, 8, 9, 0, 2, 3, 4, 5},
	{9, 0, 2, 3, 4, 5, 0, 7, 8}
	};

//	{0, 2, 3, 4, 5, 6, 7, 8, 9},
//	{4, 5, 6, 7, 8, 9, 0, 2, 3},
//	{7, 8, 9, 0, 2, 3, 4, 5, 6},
//	{2, 3, 4, 5, 6, 7, 8, 9, 0},
//	{5, 6, 7, 8, 9, 0, 2, 3, 4},
//	{8, 9, 0, 2, 3, 4, 5, 6, 7},
//	{3, 4, 5, 6, 7, 8, 9, 0, 2},
//	{6, 7, 8, 9, 0, 2, 3, 4, 5},
//	{9, 0, 2, 3, 4, 5, 6, 7, 8}
	
	if(SolveSudoku(grid)){
		PrintGrid(grid);
	} else cout << "No solution\n";
	return 0;
}
