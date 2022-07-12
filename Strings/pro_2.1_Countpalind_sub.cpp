//not completed
#include <bits/stdc++.h>
using namespace std;
bool Ispalindrome(string str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}
int countPS(string &str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i; j < str.length(); j++)
        {
            if (Ispalindrome(str, i, j))
            
                count++;
        }
    }
    return count;
}

int main()
{
    string str = "aarunsharma";
    cout<<countPS(str);
}