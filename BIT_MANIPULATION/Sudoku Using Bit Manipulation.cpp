#include <bits/stdc++.h>
using namespace std;

#define r 9
#define c 9
int arr[r][c];

void display()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void solvesoduku(int row[], int col[], int grid[3][3], int i, int j)
{
    if (i == 9)
    {

        display();
        return;
    }

    if (arr[i][j] > 0)
    {
        solvesoduku(row, col, grid, j == 8 ? i + 1 : i, j == 8 ? 0 : j + 1);
    }
    else
    {
        for (int k = 1; k < 10; k++)
        {
            if ((row[i] & 1 << k) == 0 && (col[j] & 1 << k) == 0 && (grid[i / 3][j / 3] & 1 << k) == 0)
            {
                arr[i][j] = k;
                row[i] ^= 1 << k;
                col[j] ^= 1 << k;
                grid[i / 3][j / 3] ^= 1 << k;
                solvesoduku(row, col, grid, j == 8 ? i + 1 : i, j == 8 ? 0 : j + 1);
                arr[i][j] = 0;
                row[i] ^= 1 << k;
                col[j] ^= 1 << k;
                grid[i / 3][j / 3] ^= 1 << k;
                        }
        }
    }
}
int main()
{

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    int row[r] = {0};
    int col[c] = {0};
    int grid[3][3] = {0};
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int digit = arr[i][j];
            row[i] |= 1 << digit;
            col[j] |= (1 << digit);
            grid[i / 3][j / 3] |= (1 << digit);
        }
    }
    solvesoduku(row, col, grid, 0, 0);
}