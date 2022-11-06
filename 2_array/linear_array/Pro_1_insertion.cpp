#include<bits/stdc++.h>
using namespace std;
int insert(int arr[10] , int n , int cap , int pos ,int ele)
{
    if(n==cap)
    {
        cout<<"Capacity full: can't be inserted "<<endl;
        return 0;
    }

    int index=pos-1;
    // for(int i=n-1; i>=index; i--)
    // {
    //     arr[i+1]=arr[i];        
    // }
    // arr[index]=ele;
    // n++;

    for(int i=n; i>index; i--)
    arr[i] = arr[i-1];
    arr[index]=ele;
    n++;

}
int main()
{
    int arr[10]={1,2,3,4,5,7,8,9};
    insert(arr,9,20,6,60);

    for(int i=0; i<9; i++)
    {
        cout<<arr[i]<<endl;
    }
}