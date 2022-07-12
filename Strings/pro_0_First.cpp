#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str="11";
    str.push_back('a');
    str.push_back('b');

    cout<<str<<endl;

    str.pop_back();  
    str.append("abc..");

    cout<<str<<endl;
    

    for(auto ele: str)
    // if(isalnum(ele)) cout<<ele;

    if(isdigit(ele)) cout<<ele;
    cout<<endl;
    //REVERSE
    reverse(str.begin(), str.end());
    cout<<str<<endl;
}