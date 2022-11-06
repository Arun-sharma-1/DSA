#include <bits/stdc++.h>
using namespace std;
// for all unique char = all the elements in the string should be different so we will compare with j-i+1(size of substring)
int allUniqueChar(string str)
{
    int i = 0, j = 0, res = INT_MIN;
    unordered_map<char, int> umap;

    while (j < str.length())
    {
        umap[str[j]]++;
        if (umap.size() > j - i + 1) // this condition will never hit 
            j++;
        else if (umap.size() == j - i + 1)
        {
            res = max(res, j - i + 1);
            j++;
        }
        else
        {
            while (umap.size() < j - i + 1)
            {
                umap[str[i]]--;
                if (umap[str[i]] == 0)
                    umap.erase(str[i]);
                i++;
            }
            if (umap.size() == j - i + 1)
            {
                res = max(res, j - i + 1);
            }
            j++;
        }
    }
    return res;
}
int main()
{
    string str = "pwwkew";
    cout << allUniqueChar(str);
    return 0;
}