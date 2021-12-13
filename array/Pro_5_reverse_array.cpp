#include <bits/stdc++.h>
using namespace std;

void reverse_1st(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n-1-i]);
    }
}

void reverse_2nd(int arr[] , int n)
{
    int low=0; 
    int high=n-1;
    while(low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}
int main()
{
    //reverse of array
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    cout << "array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverse_2nd(arr,n);

    cout << "reverse array --> " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}