// #include<bits/stdc++.h>
// using namespace std;

// //with simple recursion
// int fib(int n)
// {
//     if(n==0 || n==1) return n;
//     else return fib(n-1)+fib(n-2);
// }
// //memoization = > storing result
// int fib_memo(int n )
// {
//     vector<int>arr(n+1,-1);

//     if(arr[n] == -1)
//     {
//         int res;
//         if(n==0 || n==1)
//             return n;
//         else
//             res = fib_memo(n-1)+fib_memo(n-2);
//         arr[n] = res;
//     }
//     return arr[n];
// }
// int main()
// {
//     cout<<fib_memo(5);
// }
#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
void findTopoSort(int node, int visitedArray[], stack<int> &st, vector<pair<int, int>> adj[])
{
    visitedArray[node] = 1;
    for (auto it : adj[node])
    {
        if (!visitedArray[it.first])
        {
            findTopoSort(it.first, visitedArray, st, adj);
        }
    }
    st.push(node);
}
void shortestTimeTaken(int src, int N, vector<pair<int, int>> adj[], int dest)
{
    // Designing the visitedArray for finding the topological sort of the ReactMemberCommunity.
    int visitedArray[N] = {0};
    stack<int> st;
    for (int i = 0; i < N; i++)
        if (!visitedArray[i])
            findTopoSort(i, visitedArray, st, adj);

    int timeArray[N];
    for (int i = 0; i < N; i++)
        timeArray[i] = 1e9;
    timeArray[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (timeArray[node] != INF)
        {
            for (auto it : adj[node])
            {
                if (timeArray[node] + it.second < timeArray[it.first])
                {
                    timeArray[it.first] = timeArray[node] + it.second;
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
        if (i == dest)
            (timeArray[i] == 1e9) ? cout << "INF " : cout << timeArray[i] << " ";
}
int main()
{
    int NumberOfMembers;
    cin >> NumberOfMembers;
    int maxi = INT_MIN;
    for (int i = 0; i < NumberOfMembers; i++)
    {
        int member;
        cin >> member;
        maxi = max(member, maxi);
    }
    vector<pair<int, int>> adj[maxi + 1];
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    int NB, NJ;
    cin >> NB;
    cin >> NJ;
    shortestTimeTaken(NB, maxi + 1, adj, NJ);
    return 0;
}
