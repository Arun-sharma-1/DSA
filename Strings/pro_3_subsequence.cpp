#include <bits/stdc++.h>
using namespace std;
bool is_subseq(string &str, string s1)
{
    // str = abcd -->a , b, c, d ,ab,ac,ad,bc,bd,cd
    int str_len = str.length();
    int s1_len = s1.length();
    int j = 0;

    if (str_len < s1_len)
        return false; // jsut for optimization
    for (int i = 0; i < str_len && j < s1_len; i++)
    {
        if (s1[j] == str[i])
        {
            j++;
        }
    }
    return (j == s1_len);
}
bool subseq(string str, string s1, int m, int n)
{
    if (n == 0)
        return true;
    if (m == 0)
        return false;

    if (str[m - 1] == s1[n - 1])
        return subseq(str, s1, m - 1, n - 1);
    else
        return subseq(str, s1, m - 1, n);
}
int print_subseq(string str, string output)
{
    if (str.length() == 0)
    {
        cout << output << " ";
        return 1; // return where it was called 
    }
    
    // not to include first characther
    print_subseq(str.substr(1), output);

    // include first characther
    print_subseq(str.substr(1), output + str[0]);

}
int main()
{
    string str = "abpd";
    string s1 = "ac";

    // cout << subseq(str, s1, 4, 2);

    print_subseq("xyz" ," ");
}