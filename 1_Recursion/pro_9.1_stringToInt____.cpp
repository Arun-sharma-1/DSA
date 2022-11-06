//NOT WORKING 
#include <bits/stdc++.h>
using namespace std;
int stringToInt(string str, int &x)
{
    if (str.length() == 0)
    {
        return 0;
    }
    int digit = str[str.length() - 1];
    x = x * 10 + digit;
    str.length()-1;
    stringToInt(str, x);
    return x;
}
int main()
{
    string str = "1234";
    // cout << typeid(str).name() << endl;
    int ans = 0;
    stringToInt(str, ans);
    cout << ans;

    return 0;
}