#include <bits/stdc++.h>
using namespace std;
//leetcode - 1095
int peakIndexInMountainArray(MountainArray &MountainArray)
{
    int n = MountainArray.length();
    int l = 0;
    int h = n - 1;

    while (h >= l)
    {
        int mid = l + (h - l) / 2;

        if (MountainArray.get(mid) < MountainArray.get(mid + 1))
            l = mid + 1;
        else
            h = mid - 1;
    }
    return l;
}
int binarySearch(MountainArray &MountainArray, int l, int h, int target)
{
    int n = MountainArray.length();

    while (h >= l)
    {
        int m = l + (h - l) / 2;

        if (MountainArray.get(m) > target)
            h = m - 1;
        else if (MountainArray.get(m) < target)
            l = m + 1;
        else
        {
            return m;
        }
    }
    return -1;
}
int reverseBinarySearch(MountainArray &MountainArray, int l, int h, int target)
{
    int n = MountainArray.length();
    while (h >= l)
    {
        int m = l + (h - l) / 2;

        if (MountainArray.get(m) == target)
            return m;

        else if (MountainArray.get(m) > target)
            l = m + 1;
        else
            h = m - 1;
    }
    return -1;
}
int findInMountainArray(int target, MountainArray &mountainArr)
{
    int n = mountainArr.length();

    int idx = peakIndexInMountainArray(mountainArr);

    int res_idx = binarySearch(mountainArr, 0, idx, target);
    if (res_idx != -1)
        return res_idx;

    int right_res_idx = reverseBinarySearch(mountainArr, idx + 1, n - 1, target);
    if (right_res_idx != -1)
        return right_res_idx;
    return -1;
}
int main()
{
    return 0;
}