#include<bits/stdc++.h>
using namespace std;
 class Stack{
    public:
 
     bool is_operator(string op)
     {
         return op=="+"|| op=="-"|| op=="*"|| op=="/";
     }
     int calculate(int a, int b, string op)
     {
            if(op=="+") return a+b;
            if(op=="-") return a-b;
            if(op=="*") return a*b;
            if(op=="/") return a/b;
            return 0;
     }
     int VPN(vector<string>&token)
     { stack<int>s;
         for(string t:token )
         {
             if(is_operator(t))
             {
                 int a,b;
                 b=s.top();
                 s.pop();
                 a=s.top();
                 s.pop();
                 s.push(calculate(a,b,t));
             }
             else // if we not use else then it is showing an error 
                 s.push(stoi(t));
            
                      
            
         }
         return s.top();
     }

 };
int main()
{   Stack s;
    vector<string>arr={"4","13","5","/","+"};
    cout<<s.VPN(arr);

    
}