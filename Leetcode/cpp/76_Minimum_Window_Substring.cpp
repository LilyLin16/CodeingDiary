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
	//  window：[left, right)
	int left = 0, right = 0; 
	int valid = 0;
	// 记录最小覆盖子串的起点和长度
	int start = 0, len = INT_MAX;
	while (right < s.size()) {
		// c是待添加到窗口中的字符
		char c = s[right];
		// 右移窗口
		right++;
		// 进行窗口内数据的更新
		if (need.count(c)) {
			window[c]++;  // key不存在会自动创建这个key，并将value赋值为0
			if (window[c] == need[c])
				valid++;
		}
		
		// 判断左侧窗口是否要收缩
		while (valid == need.size()) {  // vaild == t.size()，当t中含有重复字母时会出错
			// 更新最小覆盖子串
			if (right - left < len) {
				start = left;
				len = right - left;
			}
			// d是待从窗口中移出的字符
			char d = s[left];
			// 左移窗口
			left++;
			// 进行窗口内数据的更新
			if (need.count(d)) {
				if (window[d] == need[d])
					valid--;
				window[d]--;
			}
		}
	}
	// 返回最小覆盖子串
	return len == INT_MAX ? "" : s.substr(start, len);
}

int main(int argc, char* argv) {
	string s, t, res;
	/*
	cin >> str用法：
		可以连续从键盘读取想要的数据，以空格、tab 或换行作为分隔符；
		如果读取成功，字符后面的分隔符是残留在缓冲区的，cin>> 不做处理，可以用getline()来处理残留分隔符；
	*/
	while (cin >> s >> t){
		res = minWindow(s, t);
		cout << res << endl;
	}
	system("pause");
	return 0;
}