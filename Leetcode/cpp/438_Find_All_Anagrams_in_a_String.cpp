/**
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"
Output:
[0, 6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc"
**/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<int> findAnagrams(string s, string p) {
	if (s.empty() || s.size() < p.size()) return{};
	unordered_map<char, int> need, window;
	for (char c: p) {
		need[c]++;
	}

	int left = 0, right = 0;
	int vaild = 0;
	// 保存结果
	vector<int> res;
	while (right < s.size()) {
		char c = s[right];
		// 窗口右移
		right++;
		// 对窗口数据进行更新
		if (need.count(c)) {
			window[c]++;
			if (window[c] == need[c])
				vaild++;
		}

		// 判断窗口左侧是否需要收缩
		while (right - left >= p.size()) {
			// 当窗口符合条件时，把起始索引加入 res
			if (vaild == need.size()) {
				res.push_back(left);
			}
			char d = s[left];
			// 窗口左移
			left++;
			// 对窗口数据进行更新
			if (need.count(d)) {
				if (window[d] == need[d])
					vaild--;
				window[d]--;
			}
		}
	}
	return res;
}

int main(int argc, char *argv) {
	string s, p;
	vector<int> res;
	while (cin >> s >> p) {
		res = findAnagrams(s, p);
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
			if (i != res.size() - 1)
			{
				cout << ",";
			}
		}
		cout << endl;
	}

	system("pause");
	return 0;
}