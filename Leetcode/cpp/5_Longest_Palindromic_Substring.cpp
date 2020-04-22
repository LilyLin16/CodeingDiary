/**
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
**/

#include <iostream>
#include <string>

using namespace std;

string expandPalindrome(string s, int left, int right) {
	// ��ֹleft��right����Խ��
	while (left >= 0 && right < s.size() && s[left] == s[right]) {
		// ��������չ
		left--;
		right++;
	}
	return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
	int sz = s.size();
	if (sz < 2) return s;
	int left = 0, right = 0;
	string res;
	for (int i = 0; i < sz; i++) {
		// ���ǳ���Ϊ�����Ļ����Ӵ�
		string s1 = expandPalindrome(s, i, i);
		// ���ǳ���Ϊż���Ļ����Ӵ�
		string s2 = expandPalindrome(s, i, i + 1);
		res = res.size() > s1.size() ? res : s1;
		res = res.size() > s2.size() ? res : s2;
	}
	return res;
}

int main() {
	string s = "babad";
	cout << longestPalindrome(s) << endl;
	system("pause");
	return 0;
}