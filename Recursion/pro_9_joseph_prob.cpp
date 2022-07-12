#include<bits/stdc++.h>
using namespace std;
//if posn starts from 0
int josephKillingProblem(int n , int k)
{
    if(n==0) return 0;
    return (josephKillingProblem(n-1,k ) + k )%n;
}

//if posn starts from 1
int josephProblem(int n , int k)
{
   return josephKillingProblem(n,k) + 1;
   
}
int main()
{
    cout<<josephKillingProblem(7,3)<<endl;
    cout<<josephProblem(7,3);
    //if circular fashion of 7 people from 0 to 6 kill every 3 person and return the last one 
}