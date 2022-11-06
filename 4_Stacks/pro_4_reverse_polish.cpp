#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    bool is_operator(string op)
    {
        return op == "+" || op == "-" || op == "*" || op == "/";
    }
    int calculate(int a, int b, string op)
    {
        if (op == "+")
            return a + b;
        if (op == "-")
            return a - b;
        if (op == "*")
            return a * b;
        if (op == "/")
            return a / b;
        return 0;
    }
    int RPN(vector<string> &token)
    {
        stack<int> s;
        int res;
        for (string t : token)
        {
            if (is_operator(t))
            {
                int a, b;
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                res = calculate(a, b, t);
                // if (res != 0) // if 2/4 is coming then ans is 0 then we don't have to push the 0 inside stack
                    s.push(res);
            }
            else // if we not use else then it is showing an error
                s.push(stoi(t));
        }
        return s.top();
    }
};
int main()
{
    Stack s;
    vector<string> arr = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << s.RPN(arr);
}