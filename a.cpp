#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}
//For N elements we need N-1 iterations to sort the array
void insertion_sort(vector<int>&arr) // & arr is nessacary
{
    for(int i=1; i<arr.size(); i++)
    {
        int index = i;
        int value = arr[i];
        while (index>0 && arr[index-1]> value)
        {
            arr[index]=arr[index-1];
            index--;
        }
        arr[index]=value;
        
    }
}
void display(vector<int>arr)
{
    for (auto ele: arr)
    {
            cout<<ele<<" ";
    }
    cout<<endl;
}
int main()
{   vector<int>arr={1,2,14,1,1,2,311,123,34};
    display(arr);
    insertion_sort(arr);
    for (auto ele: arr)
    {
            cout<<ele<<" ";
    }
    return 0;
}