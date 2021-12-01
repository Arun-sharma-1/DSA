#include <bits/stdc++.h>
using namespace std;
bool bin_search_itr(vector<int>arr , int ele)
{
    int a=0;
    int b=arr.size()-1;
    while(a<=b)
    {
         
        int m = a+(b-a)/2;
        if(ele == arr[m]) return true;
        else if(ele < arr[m]) b=m-1;
        else if (ele > arr[m] ) a=m+1;
        else false;
    
    }
    return false;
}
int main()
{
     
    vector<int> arr = {56, 33, 24, 56, 98, 11, 45, 69, 6, 23, 45, 77, 43};
    sort(arr.begin() ,arr.end());
    bin_search_itr(arr,5);
    
}