#include <bits/stdc++.h>
using namespace std;
//GFG
bool hasArrayTwoCandidates(int arr[], int n, int x) 
{
	unordered_map<int,int>umap;
	for(int i=0; i<n; i++)
		umap[arr[i]]++;
	
	for(auto it=umap.begin(); it!=umap.end(); it++)
	{
		int key=it->first;
		int value=it->second;
		
		int pair = x-key;
		if(pair == key) // it  will take 4+4 two times so we are using unordered_map not unordered_set...we will check it pair == key so it should be greater than 1
		{
			if(value>1) return true;
		}
		else if(umap.find(pair)!=umap.end()) return true;
	}
	return false;
}
int main()
{
    int Arr[] = {1, 4, 45, 5,10};
    cout<<hasArrayTwoCandidates(Arr,5,8);
}

/* 
Input:
N = 6, X = 16
Arr[] = {1, 4, 45, 6, 10, 8}
Output: Yes
Explanation: Arr[3] + Arr[4] = 6 + 10 = 16

Arr[] = {1, 4, 45, 5,10}
x=8 
*/