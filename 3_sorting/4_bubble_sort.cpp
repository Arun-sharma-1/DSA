#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}
// For N elements we need N-1 iterations to sort the array
void bubble_sort(vector<int> &arr) // & arr is nessacary
{
    int flag;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        flag = 0;
        // size -1 - i coz in each iteration maxm ele is shifting toward right so we are excluding it
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (cmp(arr[j], arr[j + 1]))
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
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
    bubble_sort(arr);
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}