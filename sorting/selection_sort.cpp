#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}
void selection_sort(vector<int>&arr)
{
    for(int i=0; i<arr.size()-1; i++)
        {
            int min=i;
            for(int j=i+1; j<arr.size(); j++)
            {
                if(!cmp(arr[j],arr[min]))
                {
                    min=j;
                }
            }
            swap(arr[i],arr[min]);

        }
}
void selection_sort_new(vector<int>&arr)
{
    for(int i=0; i<arr.size()-1; i++)
    {
        for(int j=i+1; j<arr.size(); j++)
        {
            if(arr[i] > arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
}


 
void display(vector<int>&arr)
{
    for(auto ele: arr)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int>arr={12,1,143,121,33,21,0,231};
    display(arr);
    selection_sort(arr);
    display(arr);
}