/**********************************************************************************
*
* Given numRows, generate the first numRows of Pascal's triangle.
*
* For example, given numRows = 5,
* Return
*
* [
*      [1],
*     [1,1],
*    [1,2,1],
*   [1,3,3,1],
*  [1,4,6,4,1]
* ]
*
*
**********************************************************************************/

#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generate(int numRows) {
	vector<vector<int> >  pascalTriangle(numRows, vector<int>());
	for (int i = 0; i < numRows; i++)
	{
		pascalTriangle[i].resize(i + 1, 1);
		for (int j = 1; j < i; j++)
		{
			pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
		}
	}
	return  pascalTriangle;
}

void printTriangle(vector<vector<int> > res) {
	cout << "[" << endl;
	for (int i = 0; i < res.size(); i++)
	{
		for (int spce = res.size() - i - 1; spce >= 0; spce--)
		{
			cout << " ";
		}
		cout << "[";
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j];
			if (j < res[i].size() - 1)
				cout << ",";
		}
		cout << "]";
		if (i < res.size() - 1)
			cout << ",";
		cout << endl;
	}
	cout << "]";
}

int main(int argc, char * argv[])
{
	int n = 3;
	if (argc > 1){
		n = atoi(argv[1]);
	}
	printTriangle(generate(n));
	system("pause");
	return 0;
}