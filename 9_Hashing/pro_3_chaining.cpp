#include <bits/stdc++.h>
using namespace std;
class Hash
{
    int size;
    list<int> *table; // *table to make this list dynamic
public:
    Hash(int size)
    {
        this->size = size;
        table = new list<int>[size];
    }
    void insert(int ele)
    {
        int index = ele % size;
        table[index].push_back(ele);
    }
    bool search(int ele)
    {
        int index = ele % size;
        for (auto x : table[index])
            if (x == ele)
                return true;
        return false;
    }
    void remove(int ele)
    {
        int index = ele % size;
        table[index].remove(ele);
    }
};
int main()
{
    Hash mh(10);
    mh.insert(10);
    mh.insert(20);
    mh.insert(15);
    mh.insert(7);
    cout << mh.search(10) << endl;
    mh.remove(15);
    cout << mh.search(15);
    return 0;
}