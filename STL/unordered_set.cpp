#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int>set; //duplicate values are not allowed
    set.insert(10);
    set.insert(2);
    set.insert(20);
    set.insert(2);

    for(auto ele:set)
    {
        cout<<ele<<endl;
    }
}