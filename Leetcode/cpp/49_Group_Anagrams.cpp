/**
Given an array of strings, group anagrams together.
Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
["ate","eat","tea"],
["nat","tan"],
["bat"]
]
Note:
All inputs will be in lowercase.
The order of your output does not matter.
**/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>  // cout函数重载的是string类库中的string类型，而不是CString或string.h中的。

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> res;
	if (strs.empty()) return res;
	unordered_map<string, int> m;
	for (string str : strs) {
		string t = str;
		sort(t.begin(), t.end());
		if (m.find(t) == end(m)) {
			m[t] = res.size();
			res.push_back({});
		}
		res[m[t]].push_back(str);
	}
	return res;
}

int main(int argc, char* argv) {
	vector<string> strs{ "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> res = groupAnagrams(strs);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];  // add #include <string>
			if (j != res[i].size() - 1)
				cout << ",";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}