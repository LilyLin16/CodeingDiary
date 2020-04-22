/**
Given a string, find the length of the longest substring without repeating characters.
**/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
	if (s.empty()) return 0;
	/*
	利用滑动窗口的思想来解决：
	*/
	int left = 0, right = 0;  // left和right为窗口的左右边界值
	unordered_map<char, int> window; // window[key]的初始值默认为0
									 // 记录无重复字符的最长子串的长度
	int res = 0;
	while (right < s.size()) {
		char c1 = s[right];
		window[c1]++;
		right++;
		// 当窗口中出现重复字符，开始移动left缩小窗口
		while (window[c1] > 1) {
			char c2 = s[left];
			window[c2]--;
			left++;
		}
		res = max(res, right - left);
	}
	return res;
}

int main(int argc, char* argv) {
	string s;
	while (cin >> s) {
		cout << lengthOfLongestSubstring(s) << endl;
	}
	system("pause");
	return 0;
}