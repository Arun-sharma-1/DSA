#include <bits/stdc++.h>
using namespace std;
void onesandZero(int n, vector<string> &v, int one = 0, int zero = 0, string curr = "")
{
    if (n == 0)
    {
        v.push_back(curr);
        return;
    }

    if (one > zero)
    {
        onesandZero(n - 1, v, one, zero + 1, curr + "0");
    }

    onesandZero(n - 1, v, one + 1, zero, curr + "1");
}
int main()
{
    int n = 3;
    vector<string> v;
    onesandZero(n, v);
    for (string str : v)
    {
        cout << str << endl;
    }
}