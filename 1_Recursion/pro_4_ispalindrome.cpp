#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string str, int start, int end)
{
    // abba
    if (start >= end)
        return true;
    isPalindrome(str, start+1,end-1);
    return (str[start] == str[end]);
}
int main()
{
    cout<<isPalindrome("abab", 0, 4);
}