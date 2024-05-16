/*
 * @lc app=leetcode.cn id=1553 lang=cpp
 * @lcpr version=30201
 *
 * [1553] 吃掉 N 个橘子的最少天数
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int func_dg(unordered_map<int, int> &memo, int n)
    {
        // cout << n << endl;h
        // 返回n个橘子的最少天数
        if (memo[n] != 0) // 已经知道了n个橘子的最少天数
            return memo[n];
        if (n <= 2) // 当n<2时，一天最好吃一个
            return n;
        // cout << n << endl;
        // 有三种情况，选择最少的
        memo[n] = min(func_dg(memo, n / 2) + n % 2,
                      func_dg(memo, n / 3) + n % 3) +
                  1;

        return memo[n];
    }
    int minDays(int n)
    {
        unordered_map<int, int> memo; // 吃i个橘子所需要的最少天数
        memo[0] = 0;
        memo[1] = 1;
        // cout << "hello" << endl;
        return func_dg(memo, n);
        ;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 6\n
// @lcpr case=end



// @lcpr case=start
// 9209408\n
// @lcpr case=end

 */
