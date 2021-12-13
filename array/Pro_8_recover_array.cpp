#include <bits/stdc++.h>
using namespace std;
void recover_array(int input[], int output[], int n)
{

    int left, right, mid;
    mid = n / 2;
    int i = 0;
    if (n % 2 != 0)
    {
        output[mid] = input[0];
        left = mid - 1;
        right = mid + 1;
        i++;
    }
    else
    {
        left = mid - 1;
        right = mid;
    }

    while (i < n)
    {
        output[left] = input[i];
        left--;
        i++;

        output[right] = input[i];
        right++;
        i++;
    }
}
 
int main()
{
    int input[6];
    for (int i = 0; i < 6; i++)
        cin >> input[i];
    int n = sizeof(input) / sizeof(input[0]);
    int output[6] = {};
    recover_array(input, output, n);
    
    for (int i = 0; i < 6; i++)
        cout << output[i] << " ";
 
    return 0;
}