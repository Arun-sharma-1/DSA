#include <bits/stdc++.h>
using namespace std;
// find the number that is present odd number of times in array
int oddTimes(int arr[], int n)
{
    // using unorderedMap
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
        umap[arr[i]]++;

    for (auto ele : umap)
    {
        if (ele.second % 2 != 0)
            return ele.first;
    }
    return -1;
}

int TimesOdd(int arr[], int n)
{
    // O(1) space => XOR operator
    /* 
        0 xor x = x
        1 xor 0 == 0 xor 1 =>1
        0 xor 0 => 0 
    */
    int xr = 0; 

    for (int i = 0; i < n; i++)
    {
        // xor ^ xor = 0
        //***********
        xr ^= arr[i];
    }
    return xr;
}
int main()
{
    int arr[] = {1, 2, 1, 3, 3, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << TimesOdd(arr, n);
    return 0;
}