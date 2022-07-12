#include <bits/stdc++.h>
using namespace std;
int maxx(int a, int b, int c)
{
    int ret = max(a, b);
    ret = max(ret, c);
    return ret;
}
int maxNoOfpeice(int n, int a, int b, int c)
{
    // n=23 , a =12 , b =9 ,c=11
    if (n == 0)
        return 0;
    if (n <= -1)
        return -1;
    int res = maxx(
        maxNoOfpeice(n - a, a, b, c),
        maxNoOfpeice(n - b, a, b, c),
        maxNoOfpeice(n - c, a, b, c)

    );
    if (res == -1)
        return -1;
    return ++res;
}
int main()
{
    cout << maxNoOfpeice(9, 2, 2, 2);
    return 0;
}