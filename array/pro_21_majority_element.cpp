#include <bits/stdc++.h>
using namespace std;
// majority ele =>appears more than n/2 time in array

int majorityEle(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int maxi = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                maxi++;
        }
        if (maxi > n / 2)
            return i;
    }
    return -1;
}
int findMajority(int arr[], int n)
{
    // doesn't give first index of majority element

    //1.Find a candiddate 
    int count = 1;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            res = i;
            count=1;
        }
    }

    //2.check if the candidate is actually a majority
     
     count =0;
     for(int i=0; i<n; i++)
     {
        if(arr[res == arr[i]])
        {
            count ++;
        }
     }
     if(count > n/2) return res;
     else return -1;

}
int main()
{
    int arr[] = {8, 3, 4, 8, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int index = findMajority(arr, size);
    cout<<arr[index];
}