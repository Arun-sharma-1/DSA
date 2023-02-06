#include <bits/stdc++.h>
using namespace std;
/*
brute force =>
for(int i=0; i<n; i++)
{
    for(int j=i+1; j<n; j++)
    {
        //when j is dependent on i then think about the stack approach
    }
}
 */
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long> s;
    vector<long long> res;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            res.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > arr[i])
        {
            res.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= arr[i])
        {
            while (s.size() > 0 && s.top() <= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                res.push_back(-1);
            }
            else
                res.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

/*
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long>s;
        vector<long long>res;

        for(int i=n-1; i>=0; i--)
        {
            while(s.size()>0 && s.top() <= arr[i])
            {
                s.pop();
            }
            if(s.size() == 0)
            {
                res.push_back(-1);
            }
            else res.push_back(s.top());

            s.push(arr[i]);
        }
        reverse(res.begin() , res.end());
        return res;
    }
*/
int main()
{
    int arr[] = {1, 0, 2, 1, 4};
    // output =>  3, 4 , 4, -1
    int n = sizeof(arr) / sizeof(arr[0]);
    nextGreater(arr, n);
    return 0;
}