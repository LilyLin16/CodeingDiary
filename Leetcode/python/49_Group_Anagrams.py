#!/usr/bin/env python
#coding=utf-8

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        res = []
        if not strs:
            return res
        n = len(strs)
        dic = {}
        for i in range(n):
            str = list(strs[i])
            str.sort()
            ss = "".join(str)
            if ss not in dic:
                dic[ss] = [strs[i]]
            else:
                dic[ss].append(strs[i])
        for key in dic:
            res.append(dic[key])
        return res


'''在终端输入：python 49groupAnagrams.py时就会执行main函数'''
if __name__ == "__main__":
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    res = Solution().groupAnagrams(strs)
    for s in res:
        print(s)