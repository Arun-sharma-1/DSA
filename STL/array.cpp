 #include<iostream>
#include<array>
#include<bits/stdc++.h> // for sort function 
using namespace std;
int main()
{
    // array<int,2>arr;
    // array<int,8>arr;

    // n-5;
    // array<int,n>arr;  this is error 

    array<int,5>arr{11,2,3,4,5};

    // array<int,5>arr;
    // arr={1,2,3,4,5};
    sort(arr.begin(),arr.end());
    


    for(int ele: arr)
    cout<<ele<<" ";
    cout<<endl;
    cout<<arr.at(3)<<endl; // value at 3rd index 
    cout<<"front element ="<<arr.front()<<" last element ="<<arr.back()<<endl;
    cout<<arr.data()<<endl;

    array<int,4>a{1,2};
    cout<<a.empty()<<endl;
    a.fill(10); // replace all the elements with 10 and fill the array 
    for(int ele: a)
    cout<<ele<<" ";
    cout<<a.max_size()<<endl; // give the size of array 
    cout<<a.size()<<" ";
    
    array<string,4>s={string("arun"),"kushal","rahul","ramesh"};
    // array<string,4>s={"arun","kushal","rahul","ramesh"};   BOTH ARE RIGHT 
    for(string ele : s)
    cout<<ele<<" ";
}