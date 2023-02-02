#include <bits/stdc++.h>
using namespace std;
//subarray which have sum = 0
bool subArrayExists(int arr[], int n)
{
    unordered_set<int> uset;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        //if element is 0 itself 
        if(arr[i] == 0) return true;
        
        if (prefixSum == 0)
            return true;

        // we are checking that are we getting the same no if yes then all the ele arr gone means sum is 0
        else if (uset.find(prefixSum) != uset.end())
            return true;

        uset.insert(prefixSum);
    }
    return false;
}
int main()
{
}