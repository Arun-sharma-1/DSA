#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter element of array "<<endl;
    for(int i=0; i<n; i++)
    cin>>arr[i];

    int max=INT_MIN;
    int min=INT_MAX;
    int res=INT_MIN;
    int i;
    for(i=0; i<n; i++)
    {
        if(max < arr[i])
        {
            max=arr[i]; 
            res=i;
        }   
    }
    // for(int i=0; i<n; i++)
    // {
    //     if(min > arr[i])
    //     {
    //         min=arr[i];
    //     }
    // }

    cout<<"maximum of array is "<<max<<endl;
    cout<<"Index of maximum array "<< res <<endl;
    // cout<<"minimum of array is "<<min<<endl;
     
}