#include<bits/stdc++.h>
using namespace std;
//variable size sliding window 
int longestSubarray(int arr[] ,int n,int k)
{
    int sum =0;
    int i=0,j=0;
    int ans=0;
    while(j<k)
    {
        sum+=arr[j];
        if(sum < k)
            j++;
        
        else if(sum==k)
        {
            ans=max(ans,j-i+1); // j-i+1 is the length of current window size 
            j++;
        }
        else
        {
            while(sum>k)
            {
                sum-=arr[i];
                i++;
            }
            if(sum==k)
            {
                ans=max(ans,j-i+1);
            }
            j++;
        }
    }
    return ans;
}
int main()
{
    int arr[]={4,1,1,1,2,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=5;
    cout<<longestSubarray(arr,n,k);
    return 0;
}