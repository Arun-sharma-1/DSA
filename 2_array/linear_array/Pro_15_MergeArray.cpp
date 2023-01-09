#include <bits/stdc++.h>
using namespace std;

// with using extra space
void MERGE_SORT(int a[], int b[], int n1, int n2)
{
    int temp[20];
    int i = 0, j = 0;
    int k = 0;

    int t1 = n1, t2 = n2;
    while (n1 && n2)
    {
        if (a[i] < b[j])
        {
            temp[k++] = a[i++];
            n1--;
        }
        else
        {
            temp[k++] = b[j++];
            n2--;
        }
    }
    while (i < t1)
    {
        temp[k++] = a[i++];
    }

    while (j < t2)
    {
        temp[k++] = b[j++];
    }

    cout << "Array after merging: " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << temp[i] << " ";
    }
}
// WITHOUT USING EXTRA SPACE leetcode 88 -> ayushi sharma
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    // for(int k= m+n-1; k>=0; k--)
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
            k--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
    while (i >= 0)
    {
        nums1[k--] = nums1[i--];
    }
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}
int main()
{
    // already sorted given
    int a[] = {1, 2, 4, 6};
    int b[] = {3, 6, 8, 10, 12, 14};

    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);

    MERGE_SORT(a, b, n1, n2);
    return 0;
}