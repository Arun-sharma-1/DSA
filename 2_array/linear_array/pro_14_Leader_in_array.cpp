#include<bits/stdc++.h>
using namespace std;
void leader(int arr[] , int n)
{
    for(int i=0; i<n; i++)
    {
        bool flag=false;
        for(int j=i+1; j<n; j++)
        {
             
            if(arr[i]<=arr[j]){
                flag=true;
                break;
            }
             
        }
        if(flag==false)
        {
            cout<<arr[i]<<" ";
        }
    }
}

int leader_rev(int arr[] , int n)
{
    // the last element will always be leader coz nothing is greater than last element 
    int curr_leader=arr[n-1];
    cout<<curr_leader<<" ";
    for(int i=n-2; i>=0; i--)
    {
        if(curr_leader < arr[i])
        {
            curr_leader=arr[i];
            cout<<curr_leader<<" ";
        }
    }
}
int main()
{
    int arr[]={11,20,3,21,4};
    // a leader has to be greater(strictly) than the right side of the all elements
    leader_rev(arr,5);
}