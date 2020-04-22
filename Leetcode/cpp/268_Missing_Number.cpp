/**
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
Example 1:
Input: [3,0,1]
Output: 2

Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8
**/

//#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int missingNumber1(vector<int> &nums) {
	int res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (i != nums[i]) {
			res = i;
			break;
		}
	}
	return res;
}

int missngNumber2(vector<int> &nums) {
	// 先排序，后用二分查找法来寻找缺失数字
	if (nums.empty()) return -1;
	sort(nums.begin(), nums.end());
	int left = 0, right = nums.size();
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] > mid) {
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return right;
}

int missingNumber3(vector<int>& nums) {
	/**
	要求线性的时间复杂度和常数级的空间复杂度。
	那么最直观的一个方法是用等差数列的求和公式求出0到n之间所有的数字之和，
	然后再遍历数组算出给定数字的累积和，然后做减法，差值就是丢失的那个数字。
	**/
	if (nums.empty()) return -1;
	int sum = 0, n = nums.size();
	for (int i = 0; i < n; i++) {
		sum += nums[i];
	}
	return n * (n + 1) / 2 - sum;
}

int missingNumber4(vector<int> & nums) {
	/**
	位异或操作：
	**/
	int res = 0;
	for (int i = 0; i < nums.size(); ++i) {
		res ^= (i + 1) ^ nums[i];
	}
	return res;
}

int main(int argc, char * argv[]) {
	vector<int> nums{3, 0, 1};
	int res = missingNumber3(nums);
	cout << res << endl;
	cout << "bit XOR:" <<  missingNumber4(nums) << endl;
	system("pause");
	return 0;
}
