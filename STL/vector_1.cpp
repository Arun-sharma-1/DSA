#include<iostream>
#include<vector>
using namespace std;
int main()
{
   //DECLARATION
    //    vector<int>v1; // empty vector

    //    vector<int>v(5,10); //create vector of size 5 and fill all values with 10
    //    for(int ele : v)
    //    cout<<ele<<" ";
    //    cout<<endl;

    //    cout<<endl<<v[0];  // this will give garbage value 
    //    cout<<endl<<v.at(10); // this will give errors

    //INTILIZATION
        // vector<int>vec{1,2,3,4,5};
        // vector<int>ve={1,2,3,4};

        // v.push_back(11);
        // v.pop_back();
        // for(int ele : v)
        // cout<<ele<<" ";
        // v.reserve(100);

    // RESERVE

    vector<int>v;
    v.reserve(31);
    for(int i; i<=31;++i)
    { 
        v.push_back(i);
        cout<<"size is "<<v.size()<<" capacity is "<<v.capacity();
    }

    
}