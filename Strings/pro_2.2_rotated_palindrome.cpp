#include<bits/stdc++.h>
using namespace std;
bool Ispalindrome(string str)
{
    int start = 0;
    int end = str.length()-1;
    while (start < end)
    {
        if (str[start] != str[end])
            return false;
            start++;
            end--;
    }
    return true;
}
int main()
{
    string str="CBAABCD";
    rotate(str.begin() , str.begin()+3 ,str.end());
    cout<<Ispalindrome(str);
     
}