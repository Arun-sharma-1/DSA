#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

bool cmp_des(int a, int b){
    return a<b;
}

void count_sort(vector<char> &arr)
{   
    map<char,int>bkts;

    for(char c:arr)
    {
        bkts[c]++;
    }
    int i=0;
    while(i<arr.size())
    {
        for(auto pair: bkts)
        {
            int temp=0;
            while (temp <pair.second)
            {
                arr[i+temp]=pair.first;
                temp++;
            }
            i+=temp;
        }
    }

}

void counting_sort(vector<char>&arr)
{
    char k=arr[0];
    int n=arr.size();
    for(int i=0; i<n; i++)
    {
        k=max(k,arr[i]);
    }

    vector<char>count(k,0);
    for(int i=0; i<n ;i++)
    {
        count[arr[i]]++;
    }

    for(int i=1; i<=k; i++)
    {
        count[i]+=count[i-1];
    }

    vector<char>output(n);
    for(int i=n; i>=0; i--)
    {
        output[--count[arr[i]]]=arr[i];
    }

    for(int i=0; i<n; i++)
    {
        arr[i]=output[i];
    }


}

void display(vector<char> &arr){
    for(auto ele : arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}

int main(){
    vector<char> arr ={'E', 'A', 'E', 'B', 'A', 'A', 'B', 'E', 'E', 'A', 'F', 'E', 'C', 'B', 'E', 'F', 'B', 'A', 'C', 'D'};
    display(arr);
    counting_sort(arr);
    display(arr);

    return 0;
}

