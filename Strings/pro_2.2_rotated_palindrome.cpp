#include <bits/stdc++.h>
using namespace std;
bool Ispalindrome(string str)
{
    int start = 0;
    int end = str.length() - 1;
    while (start < end)
    {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}
int isRotatedPalindrome(string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        string partA = s.substr(0, i + 1);
        string partB = s.substr(i + 1, n - 1);

        if (isPalindrome(partB.append(partA)))
            return true;
    }
    return false;
}
int main()
{
    string str = "CBAABCD";
    rotate(str.begin(), str.begin() + 3, str.end()); // abcdcba
    cout << Ispalindrome(str);
}