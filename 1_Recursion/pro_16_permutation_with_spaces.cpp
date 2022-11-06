#include <bits/stdc++.h>
using namespace std;
void per_with_spaces(string str, string curr, int index , vector<string>&res)
{
    if (index == str.length())
    {
        if (curr[0] != ' ')
           res.push_back(curr);
        return;
    }
    per_with_spaces(str, curr + str[index], index + 1 , res);
    per_with_spaces(str, curr +" "+  str[index], index + 1 , res);
    return;
}
int main()
{
    vector<string>res;
    per_with_spaces("abc", "",0, res);
    for(auto i : res) cout<<i<<endl;
    return 0;
}