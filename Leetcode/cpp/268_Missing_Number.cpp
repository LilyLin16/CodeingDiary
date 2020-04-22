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
	// �����򣬺��ö��ֲ��ҷ���Ѱ��ȱʧ����
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
	Ҫ�����Ե�ʱ�临�ӶȺͳ������Ŀռ临�Ӷȡ�
	��ô��ֱ�۵�һ���������õȲ����е���͹�ʽ���0��n֮�����е�����֮�ͣ�
	Ȼ���ٱ�����������������ֵ��ۻ��ͣ�Ȼ������������ֵ���Ƕ�ʧ���Ǹ����֡�
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
	λ��������
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
