#include <bits/std++.h>
using namespace std;
bool isAllZero(unordered_map<char, int> &mp)
{
    for (auto &x : mp)
    {
        if (x.second != 0)
            return false;
    }
    return true;
}
vector<int> findAnagrams(string text, string pat)
{
    int n = text.length();
    int k = pat.length();

    vector<int> res;
    unordered_map<char, int> mp;
    for (int i = 0; i < k; i++)
    {
        mp[pat[i]]++;
    }

    int i = 0, j = 0;
    while (j < n)
    {

        if (mp.find(text[j]) != mp.end())
        {
            mp[text[j]]--;
            // j++;
        }
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (isAllZero(mp))
            {
                res.push_back(i);
            }
            if (mp.find(text[i]) != mp.end())
                mp[text[i]]++;
            i++;
            j++;
        }
    }
    return res;
}
int main()
{
}