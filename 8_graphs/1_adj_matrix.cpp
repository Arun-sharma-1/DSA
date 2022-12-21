#include <bits/stdc++.h>
using namespace std;
#define v 4
void init(int arr[][v])
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            arr[i][j] = 0;
        }
    }
}
int hasedge(int arr[][v], int src, int dest)
{
    if (arr[src][dest] == 1)
        return 1;
    return 0;
}
void addedge_dir(int arr[][v], int src, int dest)
{
    arr[src][dest] = 1;
}
void addedge_undir(int arr[][v], int src, int dest)
{
    arr[src][dest] = 1;
    arr[dest][src] = 1;
}
void print(int arr[][v])
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int adjMatrix[v][v];
    // int adjM[v][v] = { 0 };  // intialize 2d array with all values as 0
    init(adjMatrix);
    addedge_undir(adjMatrix, 0, 1);
    addedge_undir(adjMatrix, 0, 2);
    addedge_undir(adjMatrix, 2, 3);
    addedge_undir(adjMatrix, 1, 2);

    print(adjMatrix);
    // cout << hasedge(adjMatrix, 1, 2);
}