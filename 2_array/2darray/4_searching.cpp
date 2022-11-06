#include <bits/stdc++.h>
using namespace std;
bool searching(int a[3][3], int n, int key)
{
    int i = 0;
    int j = n - 1;
    while (i >= 0 && i < n && j >= 0 && j < n)
    {
        if (a[i][j] == key)
        {
            cout << i << j << endl;
            return true;
        }
        else if (a[i][j] > key)
            j--;
        else if (key > a[i][j])
            i++;
    }
    return false;
}
int main()
{
    int a[][3] = {
        {1, 11, 111},
        {20, 201, 202},
        {30, 333, 341}};
    int key;
    cin >> key;
    cout << searching(a, 3, key);
    return 0;
}