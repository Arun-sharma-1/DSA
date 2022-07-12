#NOT WORKING PROPERLY 

#include <bits/stdc++.h>
using namespace std;
int getlargest(int arr[], int n)
{
    int largest = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[largest])
        {
            largest = i;
        }
    }
    return largest;
}
int secondlargest(int arr[], int n)
{
    int largest = getlargest(arr, n);
    // cout<<largest<<endl;
    int res = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[largest])
        {
            // cout<<"here "<<endl;
            if (res == -1)
            {
                // cout<<"come here "<<endl;
                res = i;
            }

            else if (arr[i] > arr[res])
            {
                // cout<<"res block "<<endl;
                cout << res << " ";
                res = i;
            }
        }
    }
    return res;
}
int secondLarget(int arr[], int n)
{
    //check for this method
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

int main()
{
    int arr[] = {10, 20, 30, 40};

    int n = sizeof(arr) / sizeof(arr[0]);

    secondlargest(arr, n);
}