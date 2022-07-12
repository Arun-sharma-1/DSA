#include <bits/stdc++.h>
using namespace std;
void forUpper(string str, vector<int> count)
{
    for (auto ele : str)
    {
        count[ele - 65]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            cout << char(i + 65) << " " << count[i];
            cout << endl;
        }
    }
}
void forLower(string str, vector<int> count)
{
    for (auto ele : str)
    {
        count[ele - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            cout << char(i + 97) << " " << count[i];
            cout << endl;
        }
    }
}
void forAll(string str, vector<int> count)
{
    for (auto ele : str)
    {
        count[ele]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (count[i] > 0 && i >= 97)
        {
            // uppercase
            cout << char(i) << " " << count[i];
            cout << endl;
        }
        if (count[i] > 0 && i <= 90)
        {
            cout << char(i) << " " << count[i];
            cout << endl;
        }
    }
}
bool isPalindrome(string str)
{
    int front = 0;
    int end = str.length() - 1;
    int i = 0;

    while (end >= front)
    {
        if (isdigit(str[front]))
            front++;
        if (!isalnum(str[front]))
            front++;
        else if (str[front] != str[end])
            return false;
        else
        {
            front++;
            end--;
        }
    }
    return true;
}
char firstUniqueChar(string str, vector<int> count)
{
    for (auto ele : str)
    {
        count[ele]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (count[i] == 1)
            return char(i);
    }
    return '-';
}
int main()
{
    string str = "@@aAbc";
    vector<int> count(256, 0);
    cout << firstUniqueChar(str, count);
}