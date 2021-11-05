// difference between ordered and unordered 
// 1.inbuilt impementation
// 2.Time complexity 
// 3.valid keys datatype 
#include<bits/stdc++.h>
using namespace std;

int find(unordered_map<string,int>&no)
{
    auto result=no.find("a");
    if(result==no.end())
    {
        cout<<" not find ";
        return 0;
    }
    cout<<result->first<<" "<<result->second;
}
int main()
{   
    
    unordered_map<string,int>phoneno;
     phoneno["arun"]=1234;
     phoneno["kkush"]=4321;
     phoneno.insert({ {"a",1},{"b",2} });
     phoneno.insert({"z",12} );
     phoneno["lavi"];
     

    //  cout<<phoneno.at("arun")<<" ";
    //  cout<<phoneno["arun"]<<endl;
    //  map<string,int>:: iterator iter;
    //  for(iter=phoneno.begin(); iter!=phoneno.end(); iter++)
    //  {
    //       cout<<(*iter).first<<" "<<iter->second<<endl;
    //  }

    // for(auto pr: phoneno)
    // {
    //     cout<<pr.first<<" "<< pr.second<<endl;
    // }
    find(phoneno);
    
     
}