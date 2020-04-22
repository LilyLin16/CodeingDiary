#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
	vector<vector<int> > subsets(vector<int> &nums) {
		vector<vector<int> > res(1);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			int size = res.size();
			for (int j = 0; j < size; ++j) {
				cout << j << ": ";
				printVector(res[j]);
				res.push_back(res[j]);
				cout << "res.size: " << res.size() <<" res.back(): " << endl;
				printVector(res.back());
				res.back().push_back(nums[i]);
			}
		}
		return res;
	}
	void printSets(vector<vector<int> > res) {
		for (size_t i = 0; i < res.size(); i++)
		{
			for (size_t j = 0; j < res[i].size(); j++)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
	void printVector(vector<int>res) {
		for (size_t i = 0; i < res.size(); i++)
		{
				cout << res[i] << " ";
		}
		cout << endl;
	}
};

int main(int argc, char* argv[])
{
	vector<int> num{ 1, 3, 2 };
	vector<vector<int> > res;
	Solution mySolution;
	res = mySolution.subsets(num);
	cout << "subsets: " << endl;
	mySolution.printSets(res);
	system("pause");
	return 0;
}