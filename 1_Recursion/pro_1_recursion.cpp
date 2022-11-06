#include <bits/stdc++.h>
using namespace std;
void rec(int x)
{
    if (x == 0)
        return;
    cout << "Recursion -> " << x << endl;
    rec(--x / 2); // rec(x-1) .... but not rec(x--)
}
// decimal to binary conversion
void DTB(int n)
{
    if (n == 0)
        return;
    DTB(n / 2);
    cout << n % 2;
}
// print n to 1 using recursion
int printNumbers(int n)
{
    if (n == 0)
        return 0;
    cout << n << endl;
    printNumbers(n - 1);
}
int reverseNumber(int n)
{
    if (n == 0)
        return n;
    // 1234
    int rem = n % 10;
    static int rev = 0;
    rev = rev * 10 + rem;
    reverseNumber(n / 10);
    return rev;
}
void reverseString(string str)
{
    if (str.length() == 0)
        return;

    string sub = str.substr(1);
    reverseString(sub);
    cout << str[0] << endl;
}
int main()
{
    // DTB(7);
    printNumbers(3);
    return 0;
}

*/ 
1) kth-grammer => https://leetcode.com/problems/k-th-symbol-in-grammar
*/