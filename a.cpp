#include <bits/stdc++.h>
using namespace std;
#define d 256
void rabinKarp(string &str, string &patt, int q)
{
    int strLen = str.length();
    int pattLen = patt.length();

    int h = 1;
    for (int i = 0; i < pattLen - 1; i++)
    {
        h = (h * d) % q;
    }
    // hash value of str, patt;
    int t = 0, p = 0;
    for (int i = 0; i < pattLen; i++)
    {
        p = ((d * p) + patt[i]) % q;
        t = ((d * t) + str[i]) % q;
    }

    for (int i = 0; i <= strLen - pattLen; i++)
    {
        if (p == t)
        {
            // sliding window
            int j;
            for (j = 0; j < pattLen; j++)
            {
                if (str[i + j] != patt[j])
                    break;
            }
            if (j == pattLen)
                cout << i << " ";
        }

        if (i < strLen - pattLen)
        {
            t = (d * (t - str[i] * h) + str[i + pattLen]) % q;
        }
        if (t < 0)
        {
            t = t + q;
        }
    }
}
int main()
{
    string str = "arunsharma";
    string patt = "run";

    int primeNO = 101;
    rabinKarp(str, patt, primeNO);
}