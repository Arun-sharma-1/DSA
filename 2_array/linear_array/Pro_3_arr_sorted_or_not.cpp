 #include<bits/stdc++.h>
using namespace std;
int naiveapproach(int arr[] , int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] > arr[j])
            {
                cout<<"false";
                return 0;
            }
        }

    }
    cout<<"true";
}
int eff_approach(int arr[] , int n)
{
    for(int i=1; i<n; i++)
    {
        if(arr[i] < arr[i-1])   // here arr[i] > arr[i+1] won't work coz arr[i+1] will go out of the array that will be garbage value 
        {
             cout<<" false"; 
             return 0;
        }
         
    }
    cout<<"true";
}
int main()
{
    int arr[]={1,2,3};
    int n=sizeof(arr) / sizeof(arr[0]);

    //  naiveapproach(arr,n);
     eff_approach(arr,n);
     
}