/**
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.

Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
**/

#include <iostream>
#include <vector>

using namespace std;

// 子序列下标不一定是连续的
bool increasingTriplet(vector<int>& nums) {
	int n = nums.size();
	if (n < 3) return false;
	/**
	for (int i = 0; i < n - 2; i++) {
		if (nums[i] < nums[i + 1] && nums[i + 1] < nums[i + 2]) // 递增的三元子串
			return true;
	}
	return false;
	**/
	int min1 = INT_MAX, min2 = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (nums[i] <= min1) {
			min1 = nums[i];
		}
		else if (nums[i] <= min2) {
			min2 = nums[i];
		}
		else
			return true;
	}
	return false;
}

int main(int argc, char* argv) {
	vector<int> nums{ 2, 1, 3, 1, 5 };
	cout << increasingTriplet(nums) << endl;
	system("pause");
	return 0;
}