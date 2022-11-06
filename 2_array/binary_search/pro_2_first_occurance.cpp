#include<bits/stdc++.h>
using namespace std;
//complexity of this solution is logn 
int firstOccurance(int arr[] ,int n , int ele)
{
    int low = 0, high = n-1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] > ele) high = mid-1;
        else if(arr[mid]<ele) low =mid+1;
        if(arr[mid] == ele)
        {
            //we found the element
            if(mid ==0 || arr[mid]!=arr[mid-1]) return mid; // mid == 0 to check whether it's first element or not 
             //if not satisfy any conidition put if(mid == 0 || arr[mid]!=arr[mid-1])
            else high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[]={5,10,10,20,20};
    int n =sizeof(arr)/sizeof(arr[0]);
    int ele;
    cin>>ele;
    cout<<firstOccurance(arr,n,ele);
    return 0;
}