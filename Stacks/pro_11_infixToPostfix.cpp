#include <bits/stdc++.h>
using namespace std;
bool HasHigherPrecedence(char op1, char op2)
{
    if (op1 == '(')
        return true;
    if (op2 == ')')
        return true;
    if (op1 == '+' && op2 == '-')
        return true;
    if (op1 == '*' && op2 == '/')
        return true;
    if (op1 == '*' && op2 == '+')
        return true;
    if (op1 == '*' && op2 == '-')
        return true;
    if (op1 == '/' && op2 == '+')
        return true;
    if (op1 == '/' && op2 == '-')
        return true;
    if (op1 == '-' && op2 == '+')
        return true;
    if (op1 == '/' && op2 == '*')
        return true;

    return false;
}
bool isOpeningBracket(char op1)
{
    return (op1 == '(');
}
string infixToPrefix(string exp)
{
    reverse(exp.begin(),exp.end());
    infixToPrefix(exp);

}
string infixToPostfix(string exp)
{
    string res;

    stack<char> s;
    for (int i = 0; i < exp.length(); i++)
    {
        if (isalnum(exp[i]))
        {
            res += exp[i];
        }
        else if (!isalnum(exp[i]))
        {
            while (!s.empty() && HasHigherPrecedence(s.top(), exp[i]) && exp[i] != '(')
            {
                if(s.top()!=')')
                res += s.top();
                s.pop();
            }
            if (exp[i] != '(')
                s.push(exp[i]);
        }
        else if (exp[i] == '(')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                res += s.top();
                s.pop();
            }
            s.pop(); // to remove the )
        }
    }
    while (!s.empty())
    {
        if(s.top()!=')')
        res += s.top();
        s.pop();
    }
    return res;
}
int main()
{
    string input = "a+b*c";
    cout << infixToPostfix(input);
    cout << infixToPrefix(input);
    return 0;
}