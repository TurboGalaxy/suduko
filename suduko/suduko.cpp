#include <iostream>
using namespace std;

int output(int output[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        
        for (int j = 0; j < 9; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}



bool check(int grid[9][9], int row, int col, int num)
{
    for (int i = 0; i <= 8; i++)
    {
        if (grid[row][i] == num)
        {
            return false;
        }
    }


    for (int i = 0; i <= 8; i++)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }
 

    int ROW, COL;
    ROW = row - row % 3;
    COL = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + ROW][j + COL] == num)
                {
                return false;
                }
        }
    }
    return true;
}


bool solution(int grid[9][9], int row, int col)
{
    if (row == 8 && col == 9)
        return true;



    if (col == 9) {
        row++;
        col = 0;
    }


    if (grid[row][col] > 0)
        return solution(grid, row, col + 1);

    for (int num = 1; num <= 9; num++)
    {


        if (check(grid, row, col, num))
        {


            grid[row][col] = num;


            if (solution(grid, row, col + 1))
                return true;
        }


        grid[row][col] = 0;
    }
    return false;
}


int main()
{
    // 0 means unassigned cells
    int grid[9][9] = { { 0, 8, 0, 7, 0, 1, 0, 3, 0 },
                       { 4, 0, 9, 0, 0, 0, 0, 0, 0 },
                       { 0, 5, 0, 0, 6, 0, 4, 1, 8 },
                       { 7, 0, 0, 0, 0, 9, 0, 0, 0 },
                       { 8, 0, 0, 6, 1, 0, 5, 0, 0 },
                       { 0, 3, 5, 0, 0, 0, 0, 2, 9 },
                       { 0, 6, 0, 4, 0, 7, 0, 9, 0 },
                       { 1, 0, 0, 0, 0, 8, 0, 0, 4 },
                       { 0, 2, 0, 0, 5, 0, 0, 7, 0 } };


    if (solution(grid, 0, 0))
        output(grid);

    else
        cout << "no solution  exists " << endl;

    return 0;
}
