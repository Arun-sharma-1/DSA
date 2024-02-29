#include <bits/stdc++.h>
using namespace std;
//2d arrays are stored as array in memory only the representation is like matrix.we pass column size within function
//so that compiler can do offset (row*colwidth + col).
//If we had just Array[][] it would be impossible to find it out and hence impossible to dereference an array element we need.
void print(int a[][3], int m, int n)
{
    // changing data
    //  a[0][0]=100;
    int value = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = value;
            value++;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void booleanMatrix(vector<vector<int>> &matrix)
{
    //GFG PROBLEM
    // code here
    int r = matrix.size();    // rows in vector matrix
    int c = matrix[0].size(); // column in vector matrix

    vector<int> row(r, 0);
    vector<int> col(c, 0);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 1)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 1;
            }
        }
    }
}
void searching(int arr[][3], int m, int n, int ele)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == ele)
            {
                cout << "element is present at a[" << i << "]"
                     << "[" << j << "]" << endl;
                return;
            }
        }
    }
    cout << "element is not present" << endl;
}
void printWaveform(int arr[][3], int m, int n)
{
    // in wave form col will be constant
    for (int col = 0; col < n; col++)
    {
        if (col % 2 == 0)
        {
            // top-down
            for (int row = 0; row < m; row++)
            {
                cout << arr[row][col] << " ";
            }
        }
        else
        {
            // bottom-up
            for (int row = m - 1; row >= 0; row--)
            {
                cout << arr[row][col] << " ";
            }
        }
    }
}
void snakePattern(int arr[][3], int n)
{
    int sc = 0;
    int ec = n - 1;
    for (int row = 0; row < n; row++)
    {

        if (row % 2 == 0)
        {
            for (int col = 0; col < n; col++)
            {
                cout << arr[row][col] << " ";
            }
        }
        else
        {
            for (int col = n - 1; col >= 0; col--)
            {
                cout << arr[row][col] << " ";
            }
        }
    }
}
void spiralPrint(int arr[][3], int m, int n)
{
    int startRow = 0;
    int startCol = 0;
    int endRow = m - 1;
    int endCol = n - 1;

    while (startRow <= endRow && startCol <= endCol)
    {
        // for first row
        for (int i = startCol; i <= endCol; i++)
        {
            cout << arr[startRow][i] << " ";
        }
        cout << endl;
        startRow++;

        // for last column
        for (int i = startRow; i <= endRow; i++)
        {
            cout << arr[i][endCol] << " ";
        }
        endCol--;
        cout << endl;

        // for last row
        if (startRow < endRow)
            for (int i = endCol; i >= startCol; i--)
            {
                cout << arr[endRow][i] << " ";
            }
        endRow--;
        cout << endl;
        // for lst col
        if (startCol < endCol)
            for (int i = endRow; i >= startRow; i--)
            {
                cout << arr[i][startCol] << " ";
            }
        startCol++;
        cout << endl;
    }
}

int main()
{
    int a[5][3] = {0}; // initilizing 2d array with 0
    print(a, 5, 3);
    searching(a, 5, 3, 11);
    printWaveform(a, 5, 3);
    cout << endl;
    spiralPrint(a, 5, 3);
    return 0;
}