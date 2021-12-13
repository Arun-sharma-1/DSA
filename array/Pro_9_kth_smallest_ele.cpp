#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int arr[6]={2,12,4,0,8,10};
    int k;
    cin>>k;
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<arr[k-1];
}
