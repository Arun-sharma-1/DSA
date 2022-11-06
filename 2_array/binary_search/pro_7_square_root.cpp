#include <bits/stdc++.h>
using namespace std;
int squareRoot(int N)
{
    // complexity O(root N)
    //  int res = sqrt(N); // sqrt function
    int i = 1;
    while (i * i <= N)
    {
        i++;
    }
    return i - 1;
}
int Root(int x)
{
    // complexity = O(logn)
    int low = 1, high = x;
    int ans = -1;

    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        int midSq = mid * mid;

        if (midSq == x)
            return mid; // if its perfact square otherwise we will return the floor value
        if (midSq > x)
            high = mid - 1;
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}
int main()
{
    cout << squareRoot(6) << endl;
    cout << Root(8);
    return 0;
}