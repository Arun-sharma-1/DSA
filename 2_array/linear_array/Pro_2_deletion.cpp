#include <bits/stdc++.h>
using namespace std;
int deleteElement(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (x == arr[i])
            break;
    cout << i << endl;
    if (i == n)
        return -1;
    if (i < n)
    {
        for (int j = i; j < n; j++)
        {
            arr[j] = arr[j + 1];
        }
        n--;
    }

    return n; // returning n is nessacary to update the size
}

int main()
{
    int arr[] = {11, 15, 6, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;

    // Delete x from arr[]
    n = deleteElement(arr, n, x); // deleteElement will return  updated n to remove the garbage value

    cout << "Modified array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
