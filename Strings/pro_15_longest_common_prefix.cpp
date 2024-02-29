#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(string arr[], int N)
{
    std::sort(arr, arr + N);
    string first = arr[0];
    string last = arr[N - 1];
    string res = "";
    int len = first.size() > last.size() ? last.size() : first.size();
    for (int i = 0; i < len; i++)
    {
        if (first[i] != last[i])
            break;
        res += first[i];
    }

    return res.empty() == true ? "-1" : res;
}
int main()
{
    /*
    arr[] = {geeksforgeeks, geeks, geek,
         geezer}
        Output: gee
        Explanation: "gee" is the longest common
        prefix in all the given strings.
    */
    return 0;
}
