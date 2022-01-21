#include <bits/stdc++.h>
using namespace std;
bool Rotation(string &s1, string &s2)
{
    int M = s1.length();
    // left
    for (int i = 0; i < M - 1; i++)
    {
        for (int i = M - 1; i >= 0; i--)
        {
            s1[i + 1] = s1[i];
        }
        s1[0] = s1[M];

        if (s1 == s2)
            return true;
    }

    return false;
}
bool areRotation(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;
    return ((s1 + s2).find(s2) != string::npos);
}
int main()
{
    string s1 = "arun";
    string s2 = "ruan";
    cout << Rotation(s1, s2);
    cout << areRotation(s1, s2);
}