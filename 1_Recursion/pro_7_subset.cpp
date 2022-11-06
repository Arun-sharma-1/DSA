#include <bits/stdc++.h>
using namespace std;
void subset(string str, string curr = " ", int index = 0)
{

    if (index == str.length())
    {
        cout << curr << " ";
        return;
    }
    subset(str, curr, index + 1);
    subset(str, curr + str[index], index + 1);
}
void subset (string str, unordered_set < string >&uset, string curr =" ", int index = 0) 
{
    //base condition
    if (index == str.length ())
    {
      
        if(uset.find(curr)==uset.end())
        uset.insert(curr);
        return;
    }
  
 
    subset (str,uset, curr, index + 1);
    subset (str,uset, curr + str[index], index + 1);
 
}

int main()
{
    unordered_set<string> uset;
    subset("aaa", uset);

    for(auto x: uset)
    {
        cout<<x<<",";
    }
}