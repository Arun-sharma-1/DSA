#include<bits/stdc++.h>
using namespace std;

bool cmp_des(int a, int b){
    return a<b;
}

bool cmp(int a, int b){
    return a>b;
}

void insertion_sort(vector<int>&arr)
{   
    int j;
    for(int i=1; i<arr.size(); i++)
    {
        int curr=arr[i];
    
  
    for (j=i-1; j>=0; j--)
    {
        if(cmp(arr[j],curr))
            {
                arr[j+1]=arr[j];
            }
            else{
                break;    // important or use while 
            }

    }
    arr[j+1]=curr; 
 
        // j=i-1;
        // while(arr[j] > curr &&  j>=0)
        // {
        //     arr[j+1] = arr[j];
        //     j--;    

        // }
        // arr[j+1] =curr;
    }
}
// we assume that first card is fixed and according to that we sort all the other elements 
void insertion(vector<int>&arr)
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


void display(vector<int>&arr)
{
    for(auto ele :arr)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int>arr={12,1,134,23,11,95,5};
    display(arr);
    insertion_sort(arr);
    display(arr);
    return 0;
}