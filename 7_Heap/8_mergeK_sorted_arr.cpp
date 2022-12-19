#include <bits/stdc++.h>
using namespace std;
//hello world
class data
{
public:
    int val;
    int row;
    int col;
    data(int d, int r, int c)
    {
        val = d;
        row = r;
        col = c;
    }
};

class comparator
{
public:
    bool operator()(data &d1, data &d2)
    {
        return d1.val > d2.val;
    }
};
vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    // code here
    vector<int> ans;
    priority_queue<data, vector<data>, comparator> pq;
    for (int i = 0; i < k; i++)
    {
        data d(arr[i][0], i, 0); // creating object of data class
        pq.push(d);
    }
    while (pq.size() > 0)
    {
        data top = pq.top();
        pq.pop();
        ans.push_back(top.val);

        int r = top.row;
        int c = top.col;

        if (c + 1 < arr[r].size())
        {
            data d(arr[r][c + 1], r, c + 1);
            pq.push(d);
        }
    }
    return ans;
}
int main()
{
}