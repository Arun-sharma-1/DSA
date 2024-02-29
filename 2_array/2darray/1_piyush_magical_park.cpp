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
            else if (arr[row][col] == '#')
            {
                break;
            }
            if (col != n - 1)
                score--;
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
    // minimum value should be greter than 5
    if (k > 5)
        cout << "Yes " << k;
    else
        cout << "NO ";

    return 0;
}
/*
Piyush is lost in a magical park which contains N rows and M columns.In order to get out of park 
safely and return home, he needs atleast K amount of strength.Given a N by M pattern, your task is 
to find weather Piyush can ever escape the park.
Piyush enters the park with strength S. The park is filled with some obstacles denoted by ‘.’ , 
some magical beans denoted by ‘*’ and some blockades denoted as ‘#’. If he encounters an obstacle (.) , strength decreases by 2. If he encounters a magic bean (’ * ') , his strength increases by 5. Piyush can only walk row wise, so he starts from left of a row and moves towards right and he does this for every row. However when he encounters a blockade (#) , he cannot go any further in his current row and simply jumps to the start of a new line without losing any strength. Piyush requires a strength of 1 for every step. His strength should always be greater than K while traversing or else Piyush will get lost. Assume that Piyush can shift immediately from last of one row to the start of next one without loss of any strength, help out Piyush to escape the park. His escape is successful if he is able to return home with atleast K strength.
*/