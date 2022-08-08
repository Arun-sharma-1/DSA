#include <bits/stdc++.h>
using namespace std;
void removeDuplicates(string str, int index = 0, string newString = "")
{
    vector<bool> res(26, false);
    // basecondition

    if (index == str.length())
    {
        cout << newString;
        return;
    }
    char currentChar = str[index];

    if (newString.find(currentChar) != -1) // we found that element 
    {
        removeDuplicates(str, index + 1, newString);
    }
    else
    {
        newString += currentChar;
        removeDuplicates(str, index + 1, newString);
    }
}
int main()
{

    removeDuplicates("abbcdda");
}