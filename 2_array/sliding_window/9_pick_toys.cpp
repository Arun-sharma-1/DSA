#include <bits/stdc++.h>
using namespace std;
int totalFruit(vector<int> &fruits)
{
    int n = fruits.size();
    // variable sliding window concept
    int i = 0, j = 0, res = 0;
    int k = 2;
    if (n == 1 || n == 2)
        return n;
    unordered_map<int, int> mp;
    while (j < n)
    {
        mp[fruits[j]]++;
        if (mp.size() == k || mp.size() < k)
        {
            // cout<<"here "<<endl;
            res = max(res, j - i + 1);
            j++;
        }
        else if (mp.size() > k)
        {
            // zyada ho gya
            while (mp.size() > k)
            {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0)
                    mp.erase(fruits[i]);
                i++;
            }
            if (j - i + 1 == k)
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
    /*
    we have to pick toys of 2 category and we can pick unlimited toys in sequence it means it should contain two unique char 
    */
}