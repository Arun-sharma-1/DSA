#include <bits/stdc++.h>
using namespace std;
bool is_palindrome(string &str)
{
    int front = 0;
    int end = str.length() - 1;
    while (front < end)
    {
        if (!isalnum(str[front]))
            front++;

        if (str[front] != str[end])
            return false;
        front++;
        end--;
    }
    return true;
}
int main()
{
    string str;
    cout << "Enter string : ";
    getline(cin, str);
    if (is_palindrome(str))
        cout << "String is Palindrome " << endl;
    else
        cout << "String is not Palindrome ";
}