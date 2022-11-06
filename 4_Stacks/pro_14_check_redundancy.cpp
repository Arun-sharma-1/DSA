#include <bits/stdc++.h>
using namespace std;
bool isOperator(char a)
{
    return (a == '+' || a == '-' || a == '*' || a == '/');
}
// will check is there any operator present between the opening and closing bracket if there then it is not redundant
int checkRedundancy(string s)
{
    // code here
    int ans;
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || isOperator(s[i]))
        {
            stk.push(s[i]);
        }
        else if (s[i] == ')')
        {
            ans = 1;
            while (!stk.empty() && stk.top() != '(')
            {
                int temp = stk.top();
                if (isOperator(temp))
                {
                    ans = 0;
                }

                stk.pop();
            }
            if (ans == 1)
                return 1;
            stk.pop();
        }
    }
    return ans;
}
int main()
{
    string s = "((a+b))";
    cout << checkRedundancy(s);
    return 0;
}