/**
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.
Example:
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
**/

#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	/**
	a + b + c = 0，先排序，然后固定a，利用双指针查找数组中是否有
	b + c = -a。left从a的后一个数开始查找，right从数组后面开始查找。
	**/
	if (nums.size() < 3) return{};
	sort(nums.begin(), nums.end());
	if (nums.front() > 0 || nums.back() < 0) return{};
	vector<vector<int> > triplets;
	int n = nums.size();
	for (int i = 0; i < n - 2; i++)
	{
		if (nums[i] > 0) break;  // a
		if (i > 0 && nums[i] == nums[i - 1]) continue;  // 跳过重复数字
		int target = 0 - nums[i], left = i + 1, right = n - 1;
		while (left < right) {
			if (nums[left] + nums[right] == target) {
				triplets.push_back({ nums[i], nums[left], nums[right] });
				while (left < right && nums[left] == nums[left + 1])
				{
					left++;
				}
				while (left < right && nums[right] == nums[right - 1])
				{
					right--;
				}
				left++;
				right--;
			}
			else if (nums[left] + nums[right] < target)
			{
				while (left < right && nums[left] == nums[left + 1])
				{
					left++;
				}
				left++;
			}
			else
			{
				while (left < right && nums[right] == nums[right - 1])
				{
					right--;
				}
				right--;
			}
		}
	}
	return triplets;
}

int main(int argc, char *argv) {
	vector<vector<int> > triples;
	vector<int> nums{-4, -1, -1, 0, 1, 2};
	cout << "[";
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i];
		if (i != nums.size() - 1)
			cout << ",";
	}
	cout << "]" << endl << "treeSum equal to zero are: " << endl << "[" << endl;
	for (int i = 0; i < triples.size(); i++)
	{
		cout << "  [";
		for (int j = 0; j < triples[i].size(); j++)
		{
			cout << triples[i][j];
			if (j != triples[i].size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
	cout << "]";
	system("pause");
	return 0;
}
