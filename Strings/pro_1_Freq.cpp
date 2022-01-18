#include <bits/stdc++.h>
using namespace std;
// for lower char

void forUpper(string str, vector<int> count)
{

    for (char ele : str)
    {
        count[ele - 'A']++;
    }
    for (int i = 0; i < 26; i++)
    {

        if (count[i] > 0)
        {
            cout << (char)(i + 'A') << " " << count[i] << endl;
        }
    }
}
void forLower(string str, vector<int> count)
{
    for (auto ele : str)
    {
        count[ele - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {

        if (count[i] > 0)
        {
            cout << (char)(i + 'a') << " " << count[i] << endl;
        }
    }
}
int main()
{
    string str = "arunsharma";
    string str1 = "ARUNSHARMA";
    vector<int> count(26, 0);

    forLower(str, count);
    cout << endl;
    forUpper(str1, count);

    return 0;
}