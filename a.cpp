#include <bits/stdc++.h>
using namespace std;
int insert_ele(int arr[] ,int ele,  int posn ,int n)
{
    int index = posn-1;
    for(int i=n; i>index; i--)
    {
         arr[i] =arr[i-1];
    }
    arr[index] = ele;
    return ++n;
}
int main()
{

    int arr[6] = {10,20,40,50};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // n = insert_ele(arr,30,3,n );
    // sort(arr,arr+n);

    int k=2;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<arr[k-1];
    
    
    return 0;
}