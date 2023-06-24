#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isLastNode;

    TrieNode(char c)
    {
        data = c;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isLastNode = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0'); // empty char as root
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base conditon
        if (word.length() == 0)
        {
            root->isLastNode = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        // kya pehele se present h
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            // insert krna h
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }
    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isLastNode;
        }
        int index = word[0] - 'A';
        TrieNode *child;

        // present h
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
            return false;

        // Recursion
        return searchUtil(child, word.substr(1));
    }
    void insert(string word)
    {
        insertUtil(root, word);
    }
    bool search(string word)
    {
        return searchUtil(root, word);
    }
};
int main()
{
    Trie T;
    T.insert("ABC");
    T.insert("RUN");

    if(T.search("BCA")) cout<<"present "<<endl;
    if(T.search("RU")) cout<<"present "<<endl;
    return 0;
}