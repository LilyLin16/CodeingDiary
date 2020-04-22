#!/usr/bin/env python
#coding=utf-8

'''
使用动态规划来求解 
'''

class Solution(object):
    # 动态规划：线性搜索所有楼层
    def superEggDrop1(self, K, N):
        """
        :type K: int, eggs number
        :type N: int, floors
        :rtype: int
        """
        memo = dict()
        # 当前状态为 (K 个鸡蛋，N 层楼)
        # 返回这个状态下的最优结果
        def dp(K, N):
            # base case
            if K == 1: 
                return N
            if N == 0:
                return 0
            
            # 备忘录，避免重复计算
            if (K,N) in memo:
                return memo[(K,N)]
            
            # res初始化为正无穷
            res = float("INF")
            # 穷举所有可能的组合
            for i in range(1, N + 1):
                # 动态规划的状态转移
                res = min(
                    res, max(
                        dp(K - 1, i - 1),  # 鸡蛋碎了，楼层变为[1, i -1]
                        dp(K, N - i)  # 鸡蛋未碎，楼层变为[i + 1, N]
                        ) + 1   
                    )  # 在第i层扔了鸡蛋
            
            # 记入备忘录
            memo[(K, N)] = res
            return res

        return dp(K, N)

        # 动态规划 + 二分查找：因为状态转移方程的函数图像具有单调性，可以快速找到最小值
    def superEggDrop2(self, K, N):
        memo = dict()
        def dp(K, N):
            # base case
            if K == 1: 
                return N
            if N == 0:
                return 0
        
            # 备忘录，避免重复计算
            if (K, N) in memo:
                return memo[(K, N)]
        
                # res初始化为正无穷
            res = float("INF")
            lo, hi = 1, N
            while lo <= hi:
                mid = lo + (hi - lo) // 2  #  在第mid层扔了鸡蛋
                broken = dp(K - 1, mid - 1)  # 碎了
                unbroken = dp(K, N - mid)  # 没碎
                if broken > unbroken:
                    hi = mid - 1
                    res = min(res, broken + 1)
                else:
                    lo = mid + 1
                    res = min(res, unbroken + 1)
            
            memo[(K, N)] = res
            return res

        return dp(K, N)


print(Solution().superEggDrop1(1, 2))
print(Solution().superEggDrop2(1, 2))
print(Solution().superEggDrop1(2, 6))
print(Solution().superEggDrop2(2, 6))