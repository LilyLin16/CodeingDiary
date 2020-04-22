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
	// ������
	vector<int> res;
	while (right < s.size()) {
		char c = s[right];
		// ��������
		right++;
		// �Դ������ݽ��и���
		if (need.count(c)) {
			window[c]++;
			if (window[c] == need[c])
				vaild++;
		}

		// �жϴ�������Ƿ���Ҫ����
		while (right - left >= p.size()) {
			// �����ڷ�������ʱ������ʼ�������� res
			if (vaild == need.size()) {
				res.push_back(left);
			}
			char d = s[left];
			// ��������
			left++;
			// �Դ������ݽ��и���
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