#include<bits/stdc++.h>
using namespace std;
class Hash
{
    vector<bool>arr;
    int a,b;
    public:
    Hash(int a, int b):a(a),b(b)
    {
        arr=vector<bool>(b-a+1,false);
    }
    int hash_function(int ele)
    {
        return ele%(b-a+1);
    }
    void insert(int ele)
    {
        arr[hash_function(ele)]=true;
    }
    bool is_present(int ele)
    {
        return arr[hash_function(ele)];
    }
};
int main()
{
    Hash h(4000,4100);
    h.insert(4001);
    h.insert(5011);
    int ele;
    cin>>ele;
   if(h.is_present(ele)) 
   {
       cout<<ele<<" is present "<<endl;
   }
   else
   {
       cout<<ele<<" is not present ";
   }

    // Hash h(1,10);
    // h.insert(40);
    // h.insert(41);
    // h.insert(42); #COLLISION CONDITION
    // h.insert(52);
}