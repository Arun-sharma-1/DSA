#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> count(256, 0);
        int res;
        for (auto ele : s)
        {
            count[ele - 'a']++;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (count[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    cout<<s.firstUniqChar("shsarmha");
}