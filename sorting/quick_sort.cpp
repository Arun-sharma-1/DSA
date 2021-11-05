#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}
int partition_easy_to_understand(int a, int b, vector<int> &arr)
{
    int pivot = arr[b];
    int i = a;
    for (int j = a; j < b; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[b]);
    return i;
}
int partition(int a, int b, vector<int> &arr)
{
    int pivot = arr[b];
    int i = a - 1;

    for (int j = a; j < b; j++)
    {
        if (cmp(pivot, arr[j]))
        {
            i++; // first increement and then swap
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[b]);

    return i + 1;
}
void quick_sort(int a, int b, vector<int> &arr)
{
    if (a >= b)
        return;

    int p = partition_easy_to_understand(a, b, arr);

    quick_sort(a, p - 1, arr);
    quick_sort(p + 1, b, arr);
}

void display(vector<int> arr)
{
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {1, 2, 14, 1, 1, 2, 311, 123, 34};
    display(arr);
    quick_sort(0, arr.size() - 1, arr);
    display(arr);
    return 0;
}