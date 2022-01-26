#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,string>phonebook;
    phonebook["arun"]="4398473240";
    phonebook["kush"]="3473403249";
    string name;
    cin>>name;
    if(phonebook.find(name)==phonebook.end())
    {
        cout<<" not present ";
    }
    else{
        cout<<"Number of "<<name<<" is "<<phonebook[name]<<endl;
    }

    //print this umap
    for(auto ele: phonebook)
    {
        cout<<ele.first<<" "<<ele.second<<endl;
    }
    //second method
    for(auto it=phonebook.begin(); it!=phonebook.end(); it++)
        cout<<it->first<<" "<<it->first<<endl;

}