#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:

    bool is_operator(string s)
    {
        return s=="+" || s=="-"||s=="*"||s=="/";
    }
    int calculate(int a, int b, string op)
    {
        if(op=="+") return a+b;
        if(op=="*") return a*b;
        if(op=="-") return a-b;
        if(op=="/") return a/b;
    }
    int RPN(vector<string>&token)
    {
        stack<int>s;
        int res;
        for(string ele : token)
        {
            if(is_operator(ele))
            {
                int a, b;
                b=s.top();
                s.pop();
                a=s.top();
                s.pop();
                res =calculate(a,b,ele);
                if(res)
                    s.push(res);
            }
            else
            {
                s.push(stoi(ele));
            }

              
        }
        return s.top();
    }

     
};
int main()
{
    Stack s;
    vector<string>arr = {"1 ", "2", "7", "3", "-", "/", "2", "1", "5", "+", "*", "+"};
    cout<<s.RPN(arr);
     
    return 0;
}