#include <bits/stdc++.h>
using namespace std;
bool canPlace(vector<int> &stalls, int n, int k, int mid)
{
    int cow = stalls[0];
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - cow >= mid)
        {
            count++;
            cow = stalls[i];
        }
        if (count == k)
            return true;
    }
    return false;
}
int solve(int n, int k, vector<int> &stalls)
{

    // Write your code here
    sort(stalls.begin(), stalls.end());
    int start = 1; // start will represent min distance possible btw cows=1 as 0 will cause cows to fight
    int end = stalls[n - 1] - stalls[0];
    // end will represent max dist btw cows= max-min distance in array lets sort the array otherwise will take a lot of time to find minand max
    int res = -1;

    while (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (canPlace(stalls, n, k, mid))
        {
            start = mid + 1; /// possible ans store it and find better max min distance
            res = mid;
        }
        else
            end = mid - 1;
    }
    return res;
}
int main()
{
    return 0;
}