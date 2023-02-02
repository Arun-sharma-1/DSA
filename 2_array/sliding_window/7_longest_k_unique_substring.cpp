#include<bits/stdc++.h>
using namespace std;
int uniqueSubstring(string str ,int k)
{
    int i=0,j=0,res=INT_MIN;
    unordered_map<char,int>umap; // coz we need lenght of k unique charactherx
    while(j<str.length())
    {
        //calculations
        umap[str[j]]++; // so that we can keep track of k unique elements and their count
        if(umap.size()<k) j++;
        else if(umap.size()==k)
        {
            res = max(res,j-i+1);
            j++;
        }
        else//umap.size()>k
        {
            while(umap.size()>k)
            {
                umap[str[i]]--;
                if(umap[str[i]]==0)umap.erase(str[i]);
                i++;
            }
            if(umap.size()==k)
            {
                res=max(res,j-i+1);
            }
            j++;
        }
    }
    return res;
}
int main()
{
    string str="aabcddddde";
    //take substring , and in that different char should be k and then return length of longest substring
    int k =3;
    cout<<uniqueSubstring(str,k);
    return 0;
}