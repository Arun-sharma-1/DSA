#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    bool is_end;
    vector<Node *>next; // next is  a vector of node pointers 

    Node()
    {
        is_end=false;
        next=vector<Node *>(26, nullptr);
    }
};
class Trie
{
    Node *head;
    public:
    Trie()
    {
        head=new Node();
    }
    void insert(string word)
    {
        Node *q=head;
        for(char c :word )
        {
            if(q->next[c-'a']==nullptr)
            {
                q->next[c-'a']=new Node();
            }
            q=q->next[c-'a'];

        }
        q->is_end=true;
    }

    bool is_present(string word)
    {
        Node*q=head;

        for(char c: word)
        {
            if(q->next[c-'a']==nullptr)
            {
                return false;
            }
            q=q->next[c-'a'];
        }
        return q->is_end;
    }

};
int main()
{
   vector<string>words={"manoj","man", "arun sharma "};
    Trie trie;

    for(auto word : words)
    {
        trie.insert(word);
    }

    string w;
    getline(cin,w);

   if(trie.is_present(w))
   {
       cout<<w <<" is present ";

   }
   else
   cout<<w <<" is not present ";
}