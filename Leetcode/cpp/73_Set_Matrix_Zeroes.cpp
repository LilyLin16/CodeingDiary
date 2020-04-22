/**
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
Example 1:
Input:
[
[1,1,1],
[1,0,1],
[1,1,1]
]
Output:
[
[1,0,1],
[0,0,0],
[1,0,1]
]
Example 2:
Input:
[
[0,1,2,0],
[3,4,5,2],
[1,3,1,5]
]
Output:
[
[0,0,0,0],
[0,4,5,0],
[0,3,1,0]
]
Follow up:
	A straight forward solution using O(mn) space is probably a bad idea.
	A simple improvement uses O(m + n) space, but still not the best solution.
	Could you devise a constant space solution?
**/

#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	/**
	这道题的要求是用O(1)的空间，那么我们就不能新建数组，我们考虑就用原数组的第一行第一列来记录各行各列是否有0.
	- 先扫描第一行第一列，如果有0，则将各自的flag设置为true
	- 然后扫描除去第一行第一列的整个数组，如果有0，则将对应的第一行和第一列的数字赋0
	- 再次遍历除去第一行第一列的整个数组，如果对应的第一行和第一列的数字有一个为0，则将当前值赋0
	- 最后根据第一行第一列的flag来更新第一行第一列
	**/
	int m = matrix.size(), n = matrix[0].size();
	bool rowZero = false, colZero = false;
	for (int i = 0; i < m; i++) {
		if (matrix[i][0] == 0) {
			colZero = true;
		}
	}
	for (int j = 0; j < n; j++) {
		if (matrix[0][j] == 0) {
			rowZero = true;
		}
	}
	for (int i = 1; i < m; i++) {  
		for (int j = 1; j < n; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}
	if (rowZero) {
		for (int i = 0; i < n; i++)
		{
			matrix[0][i] = 0;
		}
	}
	if (colZero)
	{
		for (int i = 0; i < m; i++)
		{
			matrix[i][0] = 0;
		}
	}
}

int main(int argc, char* argv) {
	vector<vector<int> > matrix{ {1, 0, 1}, {1, 1, 1}, {1, 1, 1} };
	int m = matrix.size(), n = matrix[0].size();
	if (m == 0 || n == 0) return 0;
	setZeroes(matrix);
	cout << "[" << endl;
	for (int i = 0; i < m; i++) {
		cout << "  [";
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j];
			if (j != n - 1) {
				cout << ",";
			}
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;
	system("pause");

	return 0;
}
