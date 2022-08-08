 #include<bits/stdc++.h>
 using namespace std;
 class Stack
 {      int arr[10];
        int top_index;
        int size;
        public:
        Stack()
        {
            top_index=-1;
            size=0;
        }
        void push(int ele)
        {   // Push the ele into stack
            if(top_index==9)
            {
                // cout<<"overflow "<<endl;
                // return;  
                throw "stack overflow "; 
            }
            top_index++;  // first increment then add element to stack 
            arr[top_index]=ele;
            size++;

        }
        void pop()
        {
            if(top_index==-1)
            {
                cout<<"underflow "<<endl;
                return;  
            }
            top_index--;
            size--;
        }
        int top()
        {    // Return the top element
             if(top_index==-1)
            {
                cout<<" stack is empty "<<endl;
                return -1; // important 
            }
            return arr[top_index];
        }
        int get_size()
        {
            return size;
        }

 };
 int main()
 {
      
        Stack s;
    // stack<int> s;

    cout<<"Size: "<<s.get_size()<<endl;

    s.push(10);
    s.push(20);
    s.push(30);

    cout<<"Size: "<<s.get_size()<<endl;

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top();


    return 0;
 }
//  maximum number of elements in stack at run time is 3.
//  The data structure required to check whether an expression contains a balanced parenthesis is Stack 
// Which data structure is used for implementing recursion--> Stack 
//for undo/redo and forward/backward we use stack data structure

/*
  Stack s;
 

    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(12); // errror 

    cout<<s.get_size()<<endl;

   for(int i=0; i<s.get_size(); i++)
    {
        cout<<s.top()<<endl;
        s.pop(); // THIS FUNCTION ALSO REDUCES SIZE SO WE CAN'T USE  i<s.get_size() coz in each iteration size is also reducing 
    }
 
*/