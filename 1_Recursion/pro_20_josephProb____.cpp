
#include <bits/stdc++.h>
using namespace std;
// if posn starts from 0
int josephKillingProblem(int n, int k)
{
    if (n == 0)
        return 0;
    return (josephKillingProblem(n - 1, k) + k) % n; // adding k becuase if each call the index should remail fixed but after killing one person the index is reduced by 1 and % n is used for circular fashion
}

// if posn starts from 1
int josephProblem(int n, int k)

{
    return josephKillingProblem(n, k) + 1;
}
void  killingProblemOfJoseph(vector<int> &v, int k, int index, int &ans)
{
    if (v.size() == 1)
    {
        ans = v[0];
        return;
    }

    index = (index + k) % v.size();
    v.erase(v.begin() + index);
    killingProblemOfJoseph(v, k, index, ans);
}
int main()
{
    // cout<<josephKillingProblem(7,3)<<endl;
    // cout<<josephProblem(7,3);
    // if circular fashion of 7 people from 0 to 6 kill every 3 person and return the last one

    //********

    int ans;
    int n = 3  ;
    int k = 2;
    int index = 0;
    vector<int> v(n);

    for (int i = 0; i < v.size(); i++)
    {
        v[i]=i+1;
    }
    --k;
    killingProblemOfJoseph(v, k, index, ans);
    cout << ans;
}