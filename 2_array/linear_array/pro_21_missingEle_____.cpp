#include <bits/stdc++.h>
using namespace std;
/*
int MissingOneNumber(int arr[], int n)
{
    // Your code goes here
    // int sum = 0;
    // for(int i=0; i<n-1; i++) sum+=array[i];
    // return (n*(n+1))/2 - sum;

    // XOR BASED SOLUTION
    int x1 = array[0];
    for (int i = 1; i < n - 1; i++)
    {
        x1 = x1 ^ array[i];
    }
    int x2 = 0;
    for (int i = 1; i <= n; i++)
        x2 = x2 ^ i;

    return x1 ^ x2;
}
*/

//NOT WORKING 
void missingTwoNumber(int arr[] ,int n ,int m)
{
    int sum = 0; 
    for(int i=0;i <n; i++)sum+=arr[i];
    int rem = (m*(m+1))/2 -sum ;
    int avg = rem/2; // coz two numbers are missing 
    int beforeSum=0;
    int i=0;
    for(;i<n; i++)
    {
        beforeSum+=arr[i];
        if(arr[i] == avg )break; //taking sum upto avg
    }
    // beforeSum+=arr[i]; //taking the last element also
    
    int first = rem - beforeSum;
    cout<<first<<endl;
    cout<<rem<<endl;
    cout<<beforeSum<<endl;

}
int main()
{
    int arr[] = {1,2,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    missingTwoNumber(arr,n , 6);
    return 0;
}