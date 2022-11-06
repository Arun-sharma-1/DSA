#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr={18, 58, 89, 94, 96, 97, 98, 98, 100, 120};
    cout<<*lower_bound(arr.begin(),arr.end(),94)<<endl;
    cout<<*upper_bound(arr.begin(),arr.end(),94); 
}