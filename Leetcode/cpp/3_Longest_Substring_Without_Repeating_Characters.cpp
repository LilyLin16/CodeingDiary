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
	���û������ڵ�˼���������
	*/
	int left = 0, right = 0;  // left��rightΪ���ڵ����ұ߽�ֵ
	unordered_map<char, int> window; // window[key]�ĳ�ʼֵĬ��Ϊ0
									 // ��¼���ظ��ַ�����Ӵ��ĳ���
	int res = 0;
	while (right < s.size()) {
		char c1 = s[right];
		window[c1]++;
		right++;
		// �������г����ظ��ַ�����ʼ�ƶ�left��С����
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