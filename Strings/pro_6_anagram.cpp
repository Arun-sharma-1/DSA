#include<bits/stdc++.h>
using namespace std;
//O(nlogn)
bool Naive_soln(string &s1, string &s2)
{
    if(s1.length()!=s2.length()) return false;

    sort(s1.begin() , s1.end());
    sort(s2.begin() , s2.end());

    return (s1==s2);
}

//O(ns)
bool Eff_soln(string &s1, string &s2)
{
    vector<int>count(26,0);
    vector<int>count1(26,0);
    if(s1.length()!=s2.length()) return false;

    for(int i=0; i<s1.length(); i++)
    {
        count[s1[i]-'a']++;
        count[s2[i]-'a']--;
    }

    for(int i=0; i<26; i++)
    {
        if(count[i]!=0) return false;
    }
    return true;

    
}
int main()
{
    string s1="arun";
    string s2 = "arua";

    if(Eff_soln(s1,s2)) cout<<"Anagram";
    else cout<<"Not anagram ";
}