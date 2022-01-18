#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "arua r";
    vector<int> count(26, 0);

    for (char ele : str)
    {
        count[ele - 'a']++;
    }
    for (int i = 0; i < count.size(); i++)
    {
        if (count[i] > 1)
        {
            cout << (char)(i + 'a') << " " << count[i] << endl;
        }
    }
}
