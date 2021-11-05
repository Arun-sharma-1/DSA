#include<bits/stdc++.h>
using namespace std;
int get_bit(int n, int pos)
{
    return (n & (1<<pos != 0));
// if n & (1<< pos) ! =0 , then bit is 1 
}

int set_bit(int n, int pos)
{
    return(n | (1<<pos));
}

int clear_bit(int n,int pos)
{
   int mask=~(1<<pos);
   return (mask&n);
}
int main()
{
    cout<<clear_bit(5,2);

}