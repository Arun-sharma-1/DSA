#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "runshmamma";
    unordered_map<char, int> umap;

    for (auto ele : s)
    {
        umap[ele]++;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char ele = s[i];
        auto temp = umap.find(ele);

        if (temp->second > 1)
        {
            cout << ele;
            break;
        }
    }

    //this is wrong approach
    
    // for(auto ele: umap)
    // {
    //     if(ele.second>1)
    //     {
    //          cout<<ele.first;
    //          break;
    //     }
    // }
}