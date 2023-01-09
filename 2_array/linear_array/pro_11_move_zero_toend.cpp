#include<bits/stdc++.h>
using namespace std;
int approach_2nd(int arr[] , int n )
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i] , arr[count]);
            count++;
        }
    }
}
int main()
{
     int arr[] = {11,2,0,3,-4,10,0,1};

    int n = sizeof(arr) / sizeof(arr[0]);
    
    approach_2nd(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}