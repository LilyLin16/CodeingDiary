/**
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

Note:
If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
**/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string minWindow(string s, string t) {
	if (s.empty() || s.size() < t.size()) return "";
	unordered_map<char, int> need, window;  
	for (char c : t) need[c]++;

	cout << t.size() << " " << need.size() << endl;
	//  window��[left, right)
	int left = 0, right = 0; 
	int valid = 0;
	// ��¼��С�����Ӵ������ͳ���
	int start = 0, len = INT_MAX;
	while (right < s.size()) {
		// c�Ǵ���ӵ������е��ַ�
		char c = s[right];
		// ���ƴ���
		right++;
		// ���д��������ݵĸ���
		if (need.count(c)) {
			window[c]++;  // key�����ڻ��Զ��������key������value��ֵΪ0
			if (window[c] == need[c])
				valid++;
		}
		
		// �ж���ര���Ƿ�Ҫ����
		while (valid == need.size()) {  // vaild == t.size()����t�к����ظ���ĸʱ�����
			// ������С�����Ӵ�
			if (right - left < len) {
				start = left;
				len = right - left;
			}
			// d�Ǵ��Ӵ������Ƴ����ַ�
			char d = s[left];
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
	// ������С�����Ӵ�
	return len == INT_MAX ? "" : s.substr(start, len);
}

int main(int argc, char* argv) {
	string s, t, res;
	/*
	cin >> str�÷���
		���������Ӽ��̶�ȡ��Ҫ�����ݣ��Կո�tab ������Ϊ�ָ�����
		�����ȡ�ɹ����ַ�����ķָ����ǲ����ڻ������ģ�cin>> ��������������getline()����������ָ�����
	*/
	while (cin >> s >> t){
		res = minWindow(s, t);
		cout << res << endl;
	}
	system("pause");
	return 0;
}