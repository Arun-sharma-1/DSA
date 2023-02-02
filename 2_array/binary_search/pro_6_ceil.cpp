    #include<bits/stdc++.h>
using namespace std;
int ceil(int arr[],int n, int ele)
{
    int res = 0;
    int start = 0;
    int end = n-1;
    while(end>=start)
    {
        int mid = start + (end-start)/2;
        if(arr[mid] == ele) return arr[mid]; // exact match , floor and ceil will be same

        //curr ele > given ele
        if(arr[mid] > ele)
        {
            //candidate for ceil
            end = mid-1;
            res = mid;
        }
        else
        {
            start = mid+1;
        }
    }
    return arr[res];
}
int main()
{
    int arr[] = {1, 2, 3, 4, 8, 10, 10, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<ceil(arr,n,12);
    return 0;
}