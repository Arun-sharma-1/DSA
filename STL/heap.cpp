#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v1={12,23,144,11,1};
    make_heap(v1.begin(), v1.end()); // max heap 
    cout<<"front = "<< v1.front()<<" "<<"end = "<<v1.back()<<endl;
    
    v1.push_back(1000); 
    push_heap(v1.begin(), v1.end());
    // v1.push_back(1000);
    cout<<"front = "<< v1.front()<<" "<<"end = "<<v1.back()<<endl;

    pop_heap(v1.begin(),v1.end());
    v1.pop_back();
    cout<<"front = "<< v1.front()<<" "<<"end = "<<v1.back()<<endl;
    pop_heap(v1.begin(),v1.end());
    v1.pop_back();
    cout<<"front = "<< v1.front()<<" "<<"end = "<<v1.back()<<endl;




  // pop_heap(v1.begin(),v1.end());
  // cout<<v1.front()<<endl;
  // cout<<v1.back()<<endl;
  

}