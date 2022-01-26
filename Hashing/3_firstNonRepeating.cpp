#include <bits/stdc++.h>
using namespace std;
int firstNonRepeating(int arr[], int n)
{
    // Complete the function
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
    {
        umap[arr[i]]++;
    }

    for (int pr = 0; pr < n; pr++)
    {
        int key = arr[pr]; // taking key like this is nessacary coz it will check randomly here we are taking ele form starting of array
        auto temp = umap.find(key);
        if (temp->second == 1)
            return key;
    }

    return 0;
}
int main()
{
    int arr[]={-1, 2, -1, 3, 2};
    cout<<firstNonRepeating(arr,sizeof(arr)/sizeof(arr[0]));
}