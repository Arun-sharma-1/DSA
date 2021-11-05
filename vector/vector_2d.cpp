#include<bits/stdc++.h>
using namespace std;
/*
#define ROW 4
#define COL 5

int main()
{ 
	vector<vector<int> > vec;

	// Elements to insert in column
	int num = 10;

	// Inserting elements into vector
	for (int i = 0; i < ROW; i++) {
		 vector<int> v1;

		for (int j = 0; j < COL; j++) {
			v1.push_back(num);
			num += 5;
        }
		vec.push_back(v1);
	}

	// Displaying the 2D vector
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
 
	return 0;
}
*/
int main()
{
    vector<vector<int>>v(5,vector<int>(2,9));

    for(auto i : v)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
     



