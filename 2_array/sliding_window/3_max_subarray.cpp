#include <bits/stdc++.h>
using namespace std;
// BRUTE FORCE
void maxSubarray(int arr[], int n, int k)
{
    vector<int> v;
    for (int i = 0; i < n - k + 1; i++)
    {
        int max = arr[i];
        for (int j = i; j < i + k; j++)
        {
            if (arr[j] > max)
                max = arr[j];
        }
        v.push_back(max);
    }
    for (auto ele : v)
        cout << ele << " ";
}
// OPTIMAL APPROACH
void MaxSubarray(int arr[], int n, int k)
{
    list<int> l;
    vector<int> v;
    int i = 0, j = 0;
    while (j < n)
    {
        // calculations
        while (l.size() > 0 && arr[j] > l.back())
        {
            l.pop_back();
        }
        l.push_back(arr[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            v.push_back(l.front());
            if (l.front() == arr[i])
            {
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    for (auto ele : v)
        cout << ele << " ";
}
int main()
{
    int arr[] = {1, 3, -1, -3, 5, 3, 4, 2};
    /*
    1,3,-1=>3
    3,-1,-3=>3
    -1,-3,5=>5
    -3,5,3=>5
    5,3,6=>6
    3,6,7=>7
    */
    int n = sizeof(arr) / sizeof(arr[0]);

    MaxSubarray(arr, n, 3);
    return 0;
}