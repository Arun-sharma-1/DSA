#include<bits/stdc++.h>
using namespace std;
int main()
{   
    // sorted order 
     map<string,int>phoneno;
     phoneno["arun"]=1234;
     phoneno["kkush"]=4321;
     phoneno.insert({ {"a",1},{"b",2} });
     phoneno.insert({"z",12} );
     phoneno["lavi"];
     

     cout<<phoneno.at("arun");
    //  map<string,int>:: iterator iter;
    //  for(iter=phoneno.begin(); iter!=phoneno.end(); iter++)
    //  {
    //       cout<<(*iter).first<<" "<<iter->second<<endl;
    //  }

    for(auto pr: phoneno)
    {
        cout<<pr.first<<" "<< pr.second<<endl;
    }
    
     
}