#include <bits/stdc++.h>
using namespace std;
void nextGreater(int arr[], int n)
{
    vector<int> v;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > arr[i])
        {
            v.push_back(s.top());
        }
        else if(s.size()>0 && arr[i]>= s.top())
        {
            while(s.size()>0 && arr[i] >= s.top())
            {
                s.pop();
            }
            if(s.size() ==0 )
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
            
        }
        s.push(arr[i]);
    }

    for (auto ele : v)
    {
        cout << ele << " ";
    }
}
int main()
{
    int arr[] = {1, 0, 2, 1, 4};
    // output => -1,1,-1,2,-1
    int n = sizeof(arr) / sizeof(arr[0]);
    nextGreater(arr, n);
    return 0;
}