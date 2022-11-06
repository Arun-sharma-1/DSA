#include <bits/stdc++.h>
using namespace std;
bool checkSortedOrNot(vector<int> &arr, int len)
{

    if (len == 1)
    {
        return true;
    }
    if (arr[len - 1] <= arr[len - 2])
        return false;
    checkSortedOrNot(arr, len - 1);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 4};
    cout << checkSortedOrNot(arr, 5);
}