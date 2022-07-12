#include <bits/stdc++.h>
using namespace std;
void permutation(string str, int index = 0)
{
    if(index == str.length()-1)
    {
        cout<<str<<" ";
        return;
    }
    for (int j = index; j < str.length(); j++)
    {
        swap(str[index], str[j]);
        permutation(str, index + 1);
        swap(str[index], str[j]);
    }
}
int main()
{
    string str="ABC";
    permutation(str);
}