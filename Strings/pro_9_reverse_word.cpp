#include <bits/stdc++.h>
using namespace std;
void Stk_soln(string &str)
{
    stack<string> stk;
    string res = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            stk.push(res);
            res = "";
        }
        else
            res += str[i];
    }
    if (res != "")
        stk.push(res); // for last string
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}
void reverse(string &str, int start, int end)
{
    while (start < end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

//first reverse the string before space and then reverse whole string 
string reverseWord(string &str)
{
    int start = 0;
    for (int end = 0; end < str.length(); end++)
    {
        if (str[end] == ' ')
        {
            reverse(str, start, end - 1);
            start = end + 1;
        }
    }
    reverse(str, start, str.length() - 1); // for the last word 
    reverse(str, 0, str.length() - 1);
    return str;
}
int main()
{
    string str = "data structures and algorithms";
    // Stk_soln(str);
    cout << reverseWord(str);
}