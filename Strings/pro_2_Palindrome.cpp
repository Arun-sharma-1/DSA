
#include <bits/stdc++.h>
using namespace std;
bool is_palindrome(string &str)
{
    int front = 0;
    int end = str.length() - 1;
    while (front <= end)
    {
        if (isdigit(str[front]))
            front++;
        else if (!isalnum(str[front]))
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