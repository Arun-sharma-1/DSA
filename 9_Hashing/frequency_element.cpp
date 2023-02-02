#include <bits/stdc++.h>
using namespace std;
void count_frequency(vector<int> &arr)
{

    unordered_map<int, int> umap;
    for (auto ele : arr)
    {
        umap[ele]++;
    }

    for (auto ele : umap)
    {
        cout << ele.first << " " << ele.second << endl;
    }
}
void count_frequency1(vector<char> &arr)
{

    unordered_map<char, int> umap;
    for (auto ele : arr)
    {
        umap[ele]++;
    }

    for (auto ele : umap)
    {
        cout << ele.first << " " << ele.second << endl;
    }
}
int main()
{
    vector<int> arr{2, 2, 2, 11, 4, 4, 3, 4};
    count_frequency(arr);
    cout << endl;

    vector<char> str = {'a', 'b', 'c','a'};
    count_frequency1(str);

    return 0;
}