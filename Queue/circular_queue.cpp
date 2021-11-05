#include<bits/stdc++.h>
using namespace std;
class Queue
{
    int front;
    int rear;
    int arr[10];
    public:
    int size;
    Queue()
    {
        front=0;
        rear=0;
        size=0;
    }
    void push(int ele)
    {
        // if(rare==10)
        // {
        //     cout<<"saturation occur "<<endl;
        // }
        if(size==10)
        {
            cout<<"overflow "<<endl;
            return;
        }
         
        // arr[rare]=ele;
        // rare++;

        arr[rear]=ele;
        rear=(rear+1)%10;
        size++;
    }
    void pop()
    {
        if(size==0)
        {
            cout<<"underflow "<<endl;
        }
        front=(front+1)%10;
        // front++;
        size--;

    }
    int peek()
    {
           if(size==0)
           {
               cout<<"empty queue "<<endl;
           }
        return arr[front];
    }
    int get_size()
    {
        return size;
    }
};
int main()
{
      Queue q;
    
    for(int i = 1 ; i <= 10 ; i++)
        q.push(i*10);

    q.push(110); // overflow

    cout<<"Size is "<<q.get_size()<<endl; // 10

    for(int i = 1 ; i <= 10 ; i++){
        cout<<q.peek()<<" ";
        q.pop();
    }

    cout<<endl;

    cout<<"Size is "<<q.get_size()<<endl;

    q.push(10);

    cout<<"Size is "<<q.get_size()<<endl;
    cout<<q.peek()<<" ";

    return 0;
}
