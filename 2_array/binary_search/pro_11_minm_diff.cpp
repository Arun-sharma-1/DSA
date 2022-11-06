#include<bits/stdc++.h>
using namespace std;
/*we have given a key if we find the absolute difference of given with the elements , then we have to return the minm
difference , if we found the key then we have to return the index of that element otherwise -->
if the key is not present then we have to find the closest element of that key , in binary search the high and low 
are present before the element and after the element so high and low will be the nearest to the key
*/
int minmDifference(int arr[], int n ,int key)
{
    int low = 0;
    int high= n-1;
    while(high>=low)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == key) return key-arr[mid];
        else if(key > arr[mid]) low = mid+1;
        else high = mid-1;
    }
    int a = abs(arr[high] - key);
    int b = abs(arr[low] - key);
    return min(a,b);
}
int main()
{
    int arr[]={2,5,8,10,12,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minmDifference(arr,n,12);
    return 0;
}