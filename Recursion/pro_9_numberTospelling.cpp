#include <bits/stdc++.h>
using namespace std;
vector<string> number = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void numberToString(int n)
{
    if (n == 0)
    {
        cout<<"one time"<<endl;
        return;
    }
    numberToString(n / 10);
    // induction
    cout << number[n%10] << " ";
}
int main()
{
    numberToString(102);
    return 0;
}