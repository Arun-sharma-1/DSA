#include <bits/stdc++.h>
using namespace std;
#define d 256
void Rabin_karp(string &str, string &patt, int q)
{
    int m = str.length();
    int n = patt.length();
    int h = 1;
    // calculate d^m-1%q;
    for (int i = 0; i < n - 1; i++)
        h = (h * d) % q;

    cout << h << endl;
    // hash of patt and str
    int p = 0, t = 0;
    for (int i = 0; i < n; i++)
    {
        t = ((t * d) + str[i]) % q;
        p = ((p * d) + patt[i]) % q;
    }

    // comparing hash of p and t
    for (int i = 0; i < m - n; i++)
    {
        int j;

        if (p == t)
        {
            for (j = 0; j < n; j++)
                if (str[i + j] != patt[j])
                    break;
            if (j == n)
                cout << i << " ";
        }

        // computing next hash using prev if spurious hit = rolling hash
        if (i < m - n)
        {
            t = (d * (t - str[i] * h) + str[i + n]) % q;
        }
        // We might get negative value of t, converting it
        // to positive
        if (t < 0)
            t = (t + q);
    }
}
int main()
{
    string txt = "arun sharma";
    string patt = "run";

    int q = 101; // prime no
    Rabin_karp(txt, patt, q);
}