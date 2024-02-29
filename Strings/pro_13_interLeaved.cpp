#include <bits/stdc++.h>
using namespace std;

// IF ALL CHAR IN A AND B ARE DIFFERENT
//use dp or recursion  to solve this problem
bool isInterleave(string A, string B, string C)
{
    int lenA = A.length();
    int lenB = B.length();
    int lenC = C.length();  

    string res = "";

    if (lenA + lenB != lenC)
        return false;
    else if (A + B == C)
        return true;
    int j = 0, i = 0, k = 0;
    while (lenC)
    {

        if (B[j] == C[k])
        {
            j++;
            k++;
        }

        else if (A[i] == C[k])
        {
            i++;
            k++;
        }

        lenC--;
    }
    return (k == lenC);
}
int main()
{
    string str1 = "UV";
    string str2 = "XY";
    string str3 = "UXYV";

    cout << isInterleave(str1, str2, str3);
}