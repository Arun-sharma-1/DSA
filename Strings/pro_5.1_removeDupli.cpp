#include <bits/stdc++.h>
using namespace std;
// keep single duplicate
void removeAdjecentDuplicates(string &s)
{
    char prev;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (prev == *it)
        {
            s.erase(it);
            it--;
        }
        else
        {
            prev = *it;
        }
    }
}
void keepSingleadjDuplicate(string &s)
{
    string res = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[i + 1])
        {
            res += s[i];
        }
    }
    cout << res;
}
string keepSingleDuplicate(string S)
{
    string res = "";
    for (int i = 0; i < S.length(); i++)
    {
        if (res.find(S[i]) == -1)
            res.push_back(S[i]);
    }
    return res;
}
// abbaca= ca
void RemoveAllDuplicates(string &s)
{
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
        if (stk.empty())
        {
            stk.push(s[i]);
        }
        else if (stk.top() != s[i])
        {
            stk.push(s[i]);
        }
        else
        {
            stk.pop();
        }
    }
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}
int main()
{
    string str = "acaaabbbacdddd";
    RemoveAllDuplicates(str);
    // removeAdjecentDuplicates(str);
    // cout<<str;
}
