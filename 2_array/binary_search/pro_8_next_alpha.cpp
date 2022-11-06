#include<bits/stdc++.h>
using namespace std;
char nextAlpha(char arr[] ,int n ,char ele)
{
    int start = 0;
    int end = n-1;
    char res='@';
    while(end>=start)
    {
        int mid = start + (end-start)/2;
        if(arr[mid] == ele) start = mid+1;
        else if(arr[mid]> ele)
        {
            res=arr[mid];
            end=mid-1;
        }
        else start = mid+1;
        
    }
    return res;
}
int main()
{
    char arr[] = {'a','e','f','g'};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<nextAlpha(arr,n,'a');
    return 0;
}