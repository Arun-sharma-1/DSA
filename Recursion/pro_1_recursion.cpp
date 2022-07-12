#include<bits/stdc++.h>
using namespace std;
void rec(int x)
{
    if(x==0) return;
    cout<<"Recursion -> "<<x<<endl;
    rec(--x/2); // rec(x-1) .... but not rec(x--) 
}
//decimal to binary conversion
void DTB(int n)
{
    if(n==0) return;
    DTB(n/2);
    cout<<n%2;
}
//print n to 1 using recursion
int  printNumbers(int n)
{
    if(n==0) return 0;
    cout<<n<<endl;
    printNumbers(n-1);
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