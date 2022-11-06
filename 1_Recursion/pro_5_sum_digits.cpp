#include <bits/stdc++.h>
using namespace std;
int countDigits(int n)
{
    // Your code here
    if (n < 10)
        return 1;
    return 1 + countDigits(n / 10);
}
int sumDigits(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + sumDigits(n / 10);
}
int main()
{
    cout << sumDigits(253);
}