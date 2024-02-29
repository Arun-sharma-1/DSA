#include <bits/stdc++.h>
using namespace std;
int longestConsecutiveSubsequence(int arr[], int n)
{
    unordered_set<int> uset(arr, arr + n);
    int res = 1;
    for (auto x : uset)
    {
        // first time => if curr -1 is not present it means first element is current element
        if (uset.find(x - 1) == uset.end()) // this will run
        {
            int curr = 1;
            while (uset.find(x + curr) != uset.end())
                curr++;

            res = max(res, curr);
        }
    }
    return res;
}
int main()
{
    int arr[] = {1, 3, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestConsecutiveSubsequence(arr, n);
    return 0;

    /*
    nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
    */
}