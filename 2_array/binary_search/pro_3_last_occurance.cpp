#include<bits/stdc++.h>
using namespace std;
int lastOccurance(int arr[] ,int n ,int ele)
{
    int low = 0;
    int high = n-1;
    while(high>=low)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] >ele) high = mid-1;
        else if(arr[mid] < ele) low = mid+1;
        else if(arr[mid] == ele)
        {
            if( mid == n-1 || arr[mid] != arr[mid+1]) return mid; // mid == n-1 to check it is first element or not 
            else low = mid+1;
        }
    }
    return -1;
}
int main()
{
    int arr[]={5,10,10,10,10,20,20};
    int n =sizeof(arr)/sizeof(arr[0]);
    int ele;
    cin>>ele;
    cout<<lastOccurance(arr,n,ele);
    return 0;
}