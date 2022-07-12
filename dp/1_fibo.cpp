#include<bits/stdc++.h>
using namespace std;

//with simple recursion
int fib(int n)
{
    if(n==0 || n==1) return n;
    else return fib(n-1)+fib(n-2);
}
//memoization = > storing result
int fib_memo(int n )
{
    vector<int>arr(n+1,-1);
    
    if(arr[n] == -1)
    {
        int res;
        if(n==0 || n==1)
            return n;
        else 
            res = fib_memo(n-1)+fib_memo(n-2);
        arr[n] = res;
    }
    return arr[n];
}
int main()
{
    cout<<fib_memo(5);
}