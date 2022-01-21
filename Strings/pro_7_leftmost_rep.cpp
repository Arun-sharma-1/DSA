#include <bits/stdc++.h>
using namespace std;
int Left_repeating(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[i] == str[j])
                return i;
        }
    }
    return -1;
}
int LEFTMOST(string &str)
{
    vector<int> count(256, 0);
    for (auto ele : str)
    {
        count[ele]++;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (count[str[i]] > 1)
            return i;
    }
    return -1;
}
int RIGHTMOST(string &str)
{
    vector<int> count(256, 0);
    for (auto ele : str)
        count[ele]++;

    for (int i = str.length() - 1; i >= 0; i--)
        if (count[str[i]] > 1)
            return i;

    return -1;
}
int main()
{
    string str = "azAAccb";
    cout << LEFTMOST(str) << endl;
    cout << RIGHTMOST(str);

    return 0;
}