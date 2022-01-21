#include <bits/stdc++.h>
using namespace std;
vector<int> FILLLPS(string &patt, vector<int> LPS)
{
    int len = 0;
    int i = 1;
    LPS[0] = 0; // FIRST will always 0

    while (i < patt.length())
    {
        if (patt[i] == patt[len])
        {
            LPS[i] = len + 1;
            len++;
            i++;
        }
        else
        {
            if (len)
                len = LPS[len - 1];
            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }

    return LPS;
}
void KMP(string &str, string &patt)
{
    int M = str.length();
    int N = patt.length();
    int i = 0, j = 0;
    vector<int> LPS;
    FILLLPS(patt, LPS);

    while (i < M)
    {
        if (patt[j] == str[i])
        {
            i++;
            j++;
        }
        if (j == N)
        {
            cout << (i - j) << " ";
            j = LPS[j - 1]; //**
        }
        else if (i < M && patt[j] != str[i])
        {
            if (j == 0)
                i++;
            else
                j = LPS[j - 1];
        }
    }
}
int main()
{
    string str = "arunsharma";
    string patt = "run";

    KMP(str, patt);
}