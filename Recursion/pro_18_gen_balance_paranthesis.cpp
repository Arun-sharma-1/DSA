// genertate balance parenthesis
#include <bits/stdc++.h>

using namespace std;
void generateParenthesis(vector<string> &v, int open, int close, string curr = "")
{
    if (open == 0 & close == 0)
    {
        v.push_back(curr);
        return ;
    }
    if (open != 0)
    {
        generateParenthesis(v, open - 1, close, curr + "(");
    }
    if (close > open)
    {
        generateParenthesis(v, open, close - 1, curr + ")");
    }
 
}

int main()
{
    vector<string> v;
    int n;
    cout<<"Enter the Number of brackets "<<endl;
     cin>>n;
    int close = n;
    int open = n;
    generateParenthesis(v, open, close);
    for (auto i : v)
        cout << i << endl;
    return 0;
}