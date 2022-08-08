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

//NOT WORKING
void uniqueSubset(string str,unordered_set <string> stringSet , string curr = " ", int index = 0)
{

    if (index == str.length())
    {
        if (stringSet.find(curr) == stringSet.end())
        {
            return;
        }
        else
        {
            cout << curr << " ";
            stringSet.insert(curr);
            return;
        }
    }
    subset(str, stringSet, curr, index + 1);
    subset(str, stringSet, curr + str[index], index + 1);
}

int main()
{
   unordered_set <string> stringSet ;
    uniqueSubset("aaa", stringSet);
}