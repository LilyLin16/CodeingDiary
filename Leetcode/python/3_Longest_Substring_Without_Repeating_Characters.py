#!/usr/bin/env python
#coding=utf-8

from collections import defaultdict

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
       # window = dict()  # 没有初始化字典
        window = defaultdict(int)  # 初始化列表，可以对不存在的键赋值
        res, left, right = 0, 0, 0
        while right < len(s):
            c1 = s[right]
            window[ord(c1)] += 1 
            right += 1
            while window[ord(c1)] > 1:
                c2 = s[left]
                window[ord(c2)] -= 1
                left += 1
            res = max(res, right - left)
        return res

s = "pwwkew"
print(Solution().lengthOfLongestSubstring(s))
