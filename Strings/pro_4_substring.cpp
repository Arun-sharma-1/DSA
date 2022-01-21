#include <bits/stdc++.h>
using namespace std;

// IF all characthers are different in patt  then we can improve this
void Searching(string &str, string &patt)
{
    int strLen = str.length();
    int pattLen = patt.length();
    int j;

    for (int i = 0; i <= strLen - pattLen;)
    {
        for (j = 0; j < pattLen; j++)
        {
            if (patt[j] != str[i + j])
                break;
        }
        if (j == pattLen)
            cout << i << " ";
        if (j == 0)
            i++;
        else i = i + j;
    }
}

// This works for all = > same or diff pattern
void Pattern_searching(string str, string patt)
{
    int strLen = str.length();
    int pattLen = patt.length();
    int j;

    for (int i = 0; i <= strLen - pattLen; i++)
    {
        for (j = 0; j < pattLen; j++)
        {
            if (patt[j] != str[i + j])
                break;
        }
        if (j == pattLen)
            cout << i << " ";
    }
}
int main()
{
    string str = "abcdaa";
    string s1 = "cda";

    Searching(str, s1);
}