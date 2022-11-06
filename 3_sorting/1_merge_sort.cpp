#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

bool cmp_des(int a, int b){
    return a<b;
}

void merge(int a, int b, int m,vector<int>&arr)
{
    int i,j,k;
    i=j=0;
    k=a; // important , k=0 will be wrong 

    vector<int>arr1(arr.begin()+a,arr.begin()+m+1);
    //  for(int q=a; q<m+1; q++)S
    // {
    //     arr1.push_back(arr[q]);
    // }
    vector<int>arr2(arr.begin()+m+1,arr.begin()+b+1);

    while(i<arr1.size() && j<arr2.size())
    {
        if(!cmp(arr1[i] , arr2[j]))
        {
            arr[k++]=arr1[i++];
            // i++;
        }
        else
        {
            arr[k++]=arr2[j++];
            // j++;
        }
        // k++;
    }
        while(i<arr1.size())
        {
            arr[k++]=arr1[i++];
        }
         while(j<arr2.size())
        {
            arr[k++]=arr2[j++];
        }
     
    

}

 

void merge_sort(int a, int b,vector<int> &arr)
{
    if(a>=b) return; // important >=
    int m=a+(b-a)/2;  // for removing error same as (a+b)/2

    merge_sort(a,m,arr); // this is recursive and break array in single element 
    merge_sort(m+1,b,arr);

    merge(a,b,m,arr);

}

void display(vector<int> &arr){
    for(auto ele : arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {4,7,12,44,17,73,68,35,23,5,5,245,767,453};
    display(arr);
   merge_sort(0,arr.size()-1,arr);
    display(arr);

    return 0;
}