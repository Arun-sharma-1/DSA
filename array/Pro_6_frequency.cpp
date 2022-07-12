#include <bits/stdc++.h>
using namespace std;
int count_freq(int arr[], int n)
{
    int freq;
    bool check[n];
    for (int i = 0; i < n; i++)
        check[i] = 0;
    for (int i = 0; i < n; i++)
    {
        if (check[i] == 1)
            continue;

        freq = 1;
        // while(j<n && arr[i]==arr[i-1])
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                check[j] = 1;
                freq++;
            }
        }

        cout << arr[i] << " " << freq << endl;
    }
}
int findFrequency(int a[], int n)
{
    // Your code here
    sort(a, a + n);
    int freq = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
            freq++;

        else if (a[i] != a[i - 1])
        {

            cout << freq << endl;
            freq = 1;
        }
        if (i == n - 1)
        {

            cout << freq << endl;
        }
    }
}
int main()
{
    int arr[] = {10, 10, 10, 20, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    count_freq(arr, n);
}