#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> mp;
bool solve(string s1, string s2)
{
    if (s1.compare(s2) == 0)
        return true;
    if (s1.length() <= 1)
        return false;
    int n = s1.length();
    bool flag = false;

    string key = s1;
    key.push_back(' ');
    key.append(s2);

    if (mp.find(key) != mp.end())
        return mp[key];

    for (int i = 1; i <= n - 1; i++)
    {
        bool swap = solve(s1.substr(0, i), s2.substr(n - i)) &&
                    solve(s1.substr(i, n - i), s2.substr(0, n - i));

        bool noswap = solve(s1.substr(0, i), s2.substr(0, i)) &&
                      solve(s1.substr(i, n - i), s2.substr(i, n - i));

        //             bool noswap = solve(s1.substr(0,i), s2.substr(0,i)) &&
        //                              solve(s1.substr(i), s2.substr(i));

        //             bool swap = solve(s1.substr(0,i), s2.substr(n-i)) &&
        //                            solve(s1.substr(i), s2.substr(0,n-i));

        if (noswap || swap)
        {
            flag = true;
            break;
        }
    }
    mp[key] = flag;
    return mp[key];
}
int main()
{
    bool isScramble(string s1, string s2)
    {

        if (s1.length() != s2.length())
            return false;
        return solve(s1, s2);
    }
    return 0;
}