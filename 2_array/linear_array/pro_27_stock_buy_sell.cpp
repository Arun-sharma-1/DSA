#include <bits/stdc++.h>
using namespace std;
//best time to buy and sell stock 

int maxmProfit(int arr[], int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            profit += arr[i] - arr[i - 1];
        }
    }
    }
    return profit;
}
int main()
{
    int arr[] = {1, 5, 3, 8, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << maxmProfit(arr, size);
}