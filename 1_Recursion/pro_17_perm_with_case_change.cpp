#include <bits/stdc++.h>
using namespace std;
void caseChange(string str, string curr = "", int index = 0)
{
    if (index == str.length())
    {
        cout << curr << endl;
        return;
    }
    caseChange(str, curr + str[index], index + 1);
    char temp = isupper(str[index]) ? tolower(str[index]) : toupper(str[index]);
    caseChange(str, curr + temp, index + 1);
}
void caseChange(string str, vector<string> &v, string curr = "", int index = 0)
{
    if (index == str.length())
    {
        if (find(v.begin(), v.end(), curr) == v.end())
            v.push_back(curr);
        return;
    }
    if (isalpha(str[index]))
    {
        caseChange(str, v, curr + str[index], index + 1);
        char temp = isupper(str[index]) ? tolower(str[index]) : toupper(str[index]);
        caseChange(str, v, curr + temp, index + 1);
    }
    else
    {
        caseChange(str, v, curr + str[index], index + 1);
    }
}
int main()
{
    string str = "ab";
    vector<string>v;
    caseChange(str , v);
    for(auto i : v) cout<<i<<" ";
}