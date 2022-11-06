#include <bits/stdc++.h>
using namespace std;
int MagicalPark(char arr[][100], int m, int n, int score)
{
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (arr[row][col] == '*')
            {
                 
                score += 5;
                // cout<<score<<" ";
            }
            if (arr[row][col] == '.')
            {
                
                score -= 2;
                // cout<<score<<" ";
            }
            else if(arr[row][col]=='#')
            {
                break;
            }
            if(col!=n-1)score--;
        }
    }
    return score;
}
int main()
{
    char a[][100] = {
        {'.', '.', '*', '.'},
        {'.', '#', '*', '.'},
        {'*', '*', '.', '.'},
        {'#', '#', '*', '*'}};

    int k = MagicalPark(a, 4, 4, 20);
    //minimum value should be greter than 5
    if(k>5)cout<<"Yes "<<k  ;
    else cout<<"NO ";

    return 0;
}