/**
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False

Note:
	The input strings only contain lower case letters.
	The length of both given strings is in range [1, 10,000].
**/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool checkInclusion(string s1, string s2) {
	// s1�ɰ����ظ��ַ�
	if (s2.empty() || s1.size() > s2.size()) return false;
	unordered_map<char, int> need, window;
	for (char c : s1) need[c]++;

	//  window��[left, right)
	int left = 0, right = 0;
	int valid = 0;
	
	while (right < s2.size()) {
		// c�Ǵ���ӵ������е��ַ�
		char c = s2[right];
		// ���ƴ���
		right++;
		// ���д��������ݵĸ���
		if (need.count(c)) {
			window[c]++;  // key�����ڻ��Զ��������key������value��ֵΪ0
			if (window[c] == need[c])
				valid++;
		}

		// �ж���ര���Ƿ�Ҫ����: �����ǰ���ڳ��ȴ�s1�ĳ�������Ҫ����
		while (right - left >= s1.size()) {  
			// �ж��Ƿ��ҵ��˺Ϸ��Ӵ�
			if (valid == need.size())
				return true;
			// d�Ǵ��Ӵ������Ƴ����ַ�
			char d = s2[left];
			// ���ƴ���
			left++;
			// ���д��������ݵĸ���
			if (need.count(d)) {
				if (window[d] == need[d])
					valid--;
				window[d]--;
			}
		}
	}
	return false;
}

int main(int argc, char* argv) {
	string s1, s2;
	while (cin >> s1 >> s2) {
		if (checkInclusion(s1, s2))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	system("pause");
	return 0;
}