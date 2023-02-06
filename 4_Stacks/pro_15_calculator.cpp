#include <bits/stdc++.h>
using namespace std;
int calculate(string s)
{
    int n = s.length();
    int number = 0;
    int res = 0;
    int sign = 1;
    stack<int> stk;

    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        {
            number = number * 10 + (s[i] - '0');
        }
        else if (s[i] == '+')
        {
            res += number * sign;
            number = 0;
            sign = 1;
        }
        else if (s[i] == '-')
        {
            res += number * sign;
            number = 0;
            sign = -1;
        }
        else if (s[i] == '(')
        {
            stk.push(res);
            stk.push(sign);
            number = 0;
            res = 0;
            sign = 1;
        }
        else if (s[i] == ')')
        {
            res += number * sign;
            number = 0;
            int stack_top_sign = stk.top();
            stk.pop();
            int stack_pre_res = stk.top();
            stk.pop();

            res = res * stack_top_sign;
            res += stack_pre_res;
        }
    }
    res += (number * sign); // for "1+2" => 2 will be stored in number 
    return res;
}
int main()
{
}