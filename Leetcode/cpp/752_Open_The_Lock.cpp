/**
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: 
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 
The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'.
Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, 
the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, 
return the minimum total number of turns required to open the lock, or -1 if it is impossible.
**/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

// �� s[j] ���ϲ���һ��
void plusOne(string &s, int j) {
	// s[j] = ((s[j] - '0') + 1) % 10 + '0';
	if(s[j] == '9') {
		s[j] = '0';
	}
	else {
		s[j] += 1;
	}
}

// �� s[j] ���²���һ��
void minusOne(string &s, int j) {
	// s[j] = ((s[j] - '0') + 9) % 10 + '0';
	if (s[j] == '0') {
		s[j] = '9';
	}
	else {
		s[j] -= 1;
	}
}

int openLock(vector<string>& deadends, string target) {
	/* ��¼��Ҫ�������������� */
	unordered_set<string> deadlocks(deadends.begin(), deadends.end());
	if (deadlocks.find("0000") != end(deadlocks)) {
		return -1;
	}

	int step = 0;
	/* ��¼�Ѿ���ٹ������룬��ֹ�߻�ͷ· */
	unordered_set<string> visited{ {"0000"} };
	/* ����㿪ʼ��������������� */
	queue<string> q;
	q.push("0000");

	while (!q.empty()) {
		int sz = q.size();
		/* ����ǰ�����е����нڵ�����Χ��ɢ */
		for (int i = sz; i > 0; i--) {
			string cur = q.front();
			q.pop();
			
			/* �ж��Ƿ񵽴��յ� */
			if (deadlocks.find(cur) != end(deadlocks)) continue;
			if (cur == target) {
				return step;
			}

			/* ��һ���ڵ��δ�������ڽڵ������� */
			for (int j = 0; j < 4; j++) {
				string up = cur;
				plusOne(up, j);
				if (visited.find(up) == end(visited)) {
					q.push(up);
					visited.insert(up);
				}

				string down = cur;
				minusOne(down, j);
				if (visited.find(down) == end(visited)) {
					q.push(down);
					visited.insert(down);
				}
			}
		}
		step++;
	}
	return -1;
}

int main() {
	string target = "0202";
	vector<string> deadends{ "0201", "0101", "0102", "1212", "2002" };
	int step = openLock(deadends, target);
	cout << step << endl;
	
	system("pause");
	return 0;
}