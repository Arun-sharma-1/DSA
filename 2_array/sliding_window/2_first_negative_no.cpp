#include <bits/stdc++.h>
using namespace std;
// find first negative number in each window of size k
vector<int> firstNegative(int arr[], int n, int k)
{
    int i = 0, j = 0;
    list<int> l;
    vector<int> v;

    while (j < n)
    {
        // calcuations

        if (arr[j] < 0)
            l.push_back(arr[j]);
            
        if (j - i + 1 < k) j++;

        else if (j - i + 1 == k) // exact window of size k
        {
            if (l.size() == 0)
            {
                // cout<<"hrere"<<endl;
                v.push_back(0);
            }
            else
            {
                v.push_back(l.front());
                if (arr[i] == l.front())
                    l.pop_front();
            }
            i++;
            j++;
        }
    }
    return v;
}
int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28}; // -1 -1 -7 -15 -15 0
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = firstNegative(arr, n, 3);
    for (auto ele : v)
        cout << ele << " ";
    return 0;
}