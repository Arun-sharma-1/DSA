#include <bits/stdc++.h>
using namespace std;
class Hash
{
public:
    vector<bool> arr;
    int a, b;
    list<int>*table;
    Hash(int a, int b):a(a),b(b)
    {
        arr=vector<bool>(b - a + 1, false);
    }
    int hash_function(int ele)
    {
        return ele % (b - a + 1);
    }
    void insert(int ele)
    {
        table[hash_function(ele)].push_back(ele);
        // arr[hash_function(ele)] = true;
    }
    bool is_present(int ele)
    {
        return table[hash_function(ele)];
    }
};
int main()
{
    
    int ele;
    cin >> ele;
    Hash h(1,10);
    h.insert(40);
    h.insert(41);
    h.insert(42);
    h.insert(52);
    if (h.is_present(ele))
    {
        cout << "Element is present " << endl;
    }
    else
    {
        cout << "Ele is not present ";
    }
    return 0;
}