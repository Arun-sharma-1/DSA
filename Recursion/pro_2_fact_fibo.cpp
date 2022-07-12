#include <bits/stdc++.h>
using namespace std;
int fabi(int n)
{
    // base condn
    if (n == 0 || n == 1)
        return n;

    // recursion
    return fabi(n - 1) + fabi(n - 2);
     
}
int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
int main()
{
    cout<< fabi(4);
    return 0;
}