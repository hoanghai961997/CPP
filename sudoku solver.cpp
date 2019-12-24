#include<iostream>
using namespace std;

//Row check---------------------------------------------------------
bool rowcheck(int grid[9][9], int ans, int row){
		for (int i=0; i<9; i++){
			if (grid[row][i]==ans) return false;
		}
		return true;
}
//Column check------------------------------------------------------
bool colcheck(int grid[9][9], int ans, int col){
		for (int i=0; i<9; i++){
			if (grid[i][col]==ans) return false;
		}
		return true;
}	
//Box check---------------------------------------------------------
bool boxcheck(int grid[9][9], int ans, int row, int col){
	int srow = row-row%3;
	int scol = col-col%3;
	for (int i=srow; i<srow+3;i++){
		for (int j=scol; j<scol+3;j++){
		if (grid[i][j]==ans) return false;	
		}
	}
	return true;
}

bool allcheck(int grid[9][9], int row, int col, int ans)
{
    return rowcheck(grid, ans, row) && colcheck(grid, ans, col) && boxcheck(grid, ans, row, col);
}

bool checkempty(int grid[9][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

//Solve-------------------------------------------------------------
bool gridsolve(int grid[9][9])
{
    int row=0, col=0;
    if (!checkempty(grid, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
    if (allcheck(grid, row, col, num))
    {
        grid[row][col] = num;
        if (gridsolve(grid)) //Infinite loop if solution is correct, else move to next value
            return true;
        grid[row][col] = 0;
    }
    }
    return false;
}

//Print out grid----------------------------------------------------
void gridprint(int grid[9][9]){
	for (int i=0;i<9;i++){
		for (int j=0;j<9;j++){
			cout<<grid[i][j]<<" ";
		}
	cout<<endl;
	}
}

int main(){
	int sudoku[9][9]={
	{0,0,0,0,0,3,6,0,0},
	{0,0,0,0,2,0,0,0,0},
	{0,3,9,8,0,0,0,0,1},
	{9,0,0,0,4,0,0,0,3},
	{3,4,0,6,0,2,0,8,0},
	{0,6,0,0,1,0,9,0,0},
	{0,8,0,0,0,0,2,0,0},
	{0,5,6,1,3,0,4,0,0},
	{4,0,0,0,8,7,0,0,0}};
	if (gridsolve(sudoku) == true) gridprint(sudoku);
	else cout<<"No Answer";
	return 0;
}
