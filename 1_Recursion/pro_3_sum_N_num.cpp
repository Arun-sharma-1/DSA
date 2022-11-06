#include <bits/stdc++.h>
using namespace std;
int sumNnumber(int n)
{
    if (n == 0 )
        return 0;
    return n + sumNnumber(n - 1);
}
int main()
{
    cout << sumNnumber(4);
}