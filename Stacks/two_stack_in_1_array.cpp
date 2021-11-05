#include<bits/stdc++.h>
using namespace std;
#define N 6
class TwoStack
{
    int arr[N];
    int mid=N/2;
    int size;
    int top_idx_1;
    int top_idx_2;
    public:
    TwoStack()
    {
        top_idx_1=-1;
        top_idx_2=mid - 1 ; // or mid - 1 
        size=0;
    }
    void push_1(int ele)
    {
        if(top_idx_1==mid-1)
        {
            cout<<"overflow "<<endl;
            return;
        }
        arr[++top_idx_1]=ele;
        size++;
    }
    int pop_1()
    {
        if(top_idx_1==-1)
        {
            cout<<"underflow ";
            return 0;
        }
        top_idx_1--;
        size--;
    }
    int top_1()
    {
        return arr[top_idx_1];
    }
    
    void push_2(int ele)
    {
        if(top_idx_2== N - 1 ) /// n-1
        {
            cout<<"overflow";
            return;
        }
        arr[++top_idx_2]=ele;
        size++;
    }
    int pop_2()
    {
        if(top_idx_2==mid-1)
        {
            cout<<"underflow ";
            return 0;
        }
        top_idx_2--;
        size--;
    }
    int top_2()
    {
        if(top_idx_2 == mid -1 )
        {
            return -1;
        }
        return arr[top_idx_2];
    }
};
int main()
{
    TwoStack s;
    s.push_1(10);
    s.push_1(20);
    
    cout<<s.top_1()<<endl;
    cout<<s.top_2();
    
}