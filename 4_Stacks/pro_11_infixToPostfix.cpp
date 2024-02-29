#include <bits/stdc++.h>
using namespace std;
bool hashigherprecedence(char op1, char op2)
{
    if (op1 == op2)
        return true; // if both operators are same like +,+ eg=a+b+c
    if (op1 == '+' && op2 == '-' || op1 == '-' && op2 == '+') //if same precdence than also we have to return true;
        return true;
    if (op1 == '*' && op2 == '/' || op1 == '/' && op2 == '*')
        return true;

    if (op1 == '*' && op2 == '+')
        return true;
    if (op1 == '*' && op2 == '-')
        return true;
    if (op1 == '/' && op2 == '+')
        return true;
    if (op1 == '/' && op2 == '-')
        return true;
    if (op1 == '^')
        return true;

    return false;
}
string infixToPostfix(string s)
{
    // Your code here
    string res = "";
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
        if (isalnum(s[i]))
            res += s[i];
        else if (s[i] == '(')
            stk.push(s[i]);
        // this order of else if should be like this because we are handling different cases for (
        else if (s[i] == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                res += stk.top();
                stk.pop();
            }
            stk.pop(); // this pop is for (
        }

        else if (!isalnum(s[i]))
        {
            //stack m phele kam precedence wala hona chaiye fir higher precedence wala agar
            //high precedence wala h tab tak pop kro
            while (!stk.empty() && hashigherprecedence(stk.top(), s[i]))
            {

                res += stk.top();
                stk.pop();
            }

            if (s[i] != '(')
                stk.push(s[i]);
        }
    }
    while (!stk.empty())
    {
        if (stk.top() != ')')
            res += stk.top();
        stk.pop();
    }
    return res;
}
int main()
{
    // a+b+c
    string input = "A*(B+C)/D";
    cout << infixToPostfix(input);
    /*
    to find infix to prefix , first reverse the given string and apply the same operation and then agian reverset it =>#ComputerAdx
    */
    cout << infixToPrefix(input);
    return 0;
}