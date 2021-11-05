#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}
void bubble_sort(vector<int>&arr) // & arr is nessacary
{
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr.size()-1 ; j++)
        {
            if(cmp(arr[j],arr[j+1]))
            {
                swap(arr[j],arr[j+1]);
            }
        }
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
    bubble_sort(arr);
    display(arr);
    return 0;
}