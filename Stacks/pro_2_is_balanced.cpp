#include <bits/stdc++.h>
using namespace std;
bool matching(char a, char b)
{
    if ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
        return true;
    return false;
}
bool isBalanced(string str)
{
    stack<int> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(')
        {
            s.push(str[i]);
        }
        else
        {
            if(s.empty()) 
            {
                //for corner case if string is only ")"
                return false;
            }
            int top = s.top();
             
            if (matching(top, str[i]) == false)
            {
                cout<<"Hello "<<endl;
                return false;
            }
            else
            {
                s.pop();
            }
             
        }
    }
    return (s.empty() == true); //corner case 
}
int main()
{
    string str = ")";
    cout << isBalanced(str);
    return 0;
}