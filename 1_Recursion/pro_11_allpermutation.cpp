#include <bits/stdc++.h>
using namespace std;
void diffPermuatation(string str, vector<string> &result, int index = 0)
{
    // base codn
    if (index == str.length())
    {
        if (find(result.begin(), result.end(), str) == result.end())
            result.push_back(str);
        return;
    }
    for (int j = index; j < str.length(); j++)
    {
        swap(str[j], str[index]);
        diffPermuatation(str, result, index + 1);
        swap(str[index], str[j]);
    }
}
void permutation(string str, int index = 0)
{
    if (index == str.length() - 1)
    {
        cout << str << " ";
        return;
    }
    for (int j = index; j < str.length(); j++)
    {
        swap(str[index], str[j]);
        permutation(str, index + 1);
        // backtracking
        swap(str[index], str[j]); // induction condition
    }
}
int main()
{
    string str = "ABC";
    permutation(str);
}