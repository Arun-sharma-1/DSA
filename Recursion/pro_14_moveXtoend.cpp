#include <bits/stdc++.h>
using namespace std;
void moveXToEnd(string &str, int index = 0, int count = 0, string newString = "")
{
    // base condition
    if (str.length() == index)
    {
        while (count)
        {
            newString.push_back('x');
            count--;
        }

        cout << newString;
        return;
    }
    if (str[index] == 'x')
    {

        moveXToEnd(str, index + 1, count + 1, newString);
    }
    else
    {
        newString.push_back(str[index]);
        moveXToEnd(str, index + 1, count, newString);
    }
}
int main()
{
    string str = "abxcxabxa"; // abcxxabxa // abcaxxbxa // abcaxxbax
    moveXToEnd(str);
}