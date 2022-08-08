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
void nextGreater(int arr[] , int n)
{
    stack<int>s;
    vector<int>v;
    for(int i=n-1; i>=0; i--)
    {
        if(s.empty())
        {
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top() > arr[i])
        {
           
            v.push_back(s.top());
        }
        else if(s.size()>0 && s.top() <= arr[i])
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

    reverse(v.begin(),v.end());
    for(auto ele: v)
    {
        cout<<ele<<" ";
    }
}
int main()
{
    int arr[] = {10, 0, 2, 2, 4};
    //output =>  3, 4 , 4, -1
    int n = sizeof(arr) / sizeof(arr[0]);
    nextGreater(arr, n);
    return 0;
}