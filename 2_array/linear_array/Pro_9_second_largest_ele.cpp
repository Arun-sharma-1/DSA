#include <bits/stdc++.h>
using namespace std;
int largestEle(int arr[], int n)
{
    int lar = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        lar = max(lar, arr[i]);
    }
    return lar;
}
int print2largest(int arr[], int n)
{
    // code here
    int largest = largestEle(arr, n);
    int sl = -1;
    for (int i = 0; i < n; i++)
    {
        if (largest != arr[i])
        {
            sl = max(sl, arr[i]);
        }
    }
    return sl;
}
// if elements are not same then we can use priority queue

int secondLarget(int arr[], int n)
{
    // check for this method
    int largest = getLargest(arr, n);
    int secondlargest = arr[0];
    // cout<<"largest "<<largest<<endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > secondlargest && arr[i] < largest)
        {
            secondlargest = arr[i];
            // cout<<"second "<<secondlargest<<endl;
        }
    }
    return secondlargest;
}
// WORKING
int secondLargestElement(int arr[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }

    // maxi = contain maximum element
    int sl = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < maxi && arr[i] > sl)
        {
            sl = arr[i];
        }
    }
    return sl;
}

// FIND SECOND MAXIMUM ELEMENT IN SINGLE ITERATION
int print2largest(int arr[], int n)
{
    if (n < 2)
        return -1;
    int firstMax = INT_MIN, secondMax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > firstMax)
        {
            secondMax = firstMax;
            firstMax = arr[i];
        }
        else if (arr[i] > secondMax && arr[i] < firstMax) // BOTH THE CONDITION ARE NESSACARY
        {
            secondMax = arr[i];
        }
    }
    if (secondMax == INT_MIN)
        return -1;
    return secondMax;
}
int main()
{
    int arr[] = {10, 20, 30, 40};

    int n = sizeof(arr) / sizeof(arr[0]);

    secondlargest(arr, n);
}