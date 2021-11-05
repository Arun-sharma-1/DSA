// maximum sum sub-array
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return (a>b)?a:b;
}
int main()
{
    int curr=0;
    int maxTillNow=0;
    int arr[4]={-1,-2,-3,-1};

    for(int i=0; i<4; i++)
    {
        curr+=arr[i];
         maxTillNow=max(curr,maxTillNow);

        if(curr<0) 
        {
            curr=0;
        }
    }
    cout<<maxTillNow;

    
}