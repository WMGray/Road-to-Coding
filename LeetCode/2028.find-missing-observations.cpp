/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 * @lcpr version=30202
 *
 * [2028] 找出缺失的观测数据
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size(); // m
        // 剩下的sum_n
        int sum_n = (m + n) * mean - accumulate(rolls.begin(), rolls.end(), 0);
        // 先计算两种情况: sum_n 过大 || 过小
        if (sum_n < n || sum_n > n * 6)
            return {};
        // 贪心 -- 能取最大就取最大
        vector<int> ans(n);
        int i = 0;
        while (i < n)
        {
            // 如果有余裕 -- 直接来6
            if (sum_n - 6 >= (n - i - 1))
            {
                ans[i] = 6;
                sum_n -= 6;
                i++;
            }
            // 不能取最大了
            else
            {
                ans[i] = sum_n - (n - i - 1);
                i++;
                break;
            }
        }
        while (i < n)
        {
            ans[i] = 1;
            i++;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,4,3]\n4\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,5,6]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n6\n4\n
// @lcpr case=end

// @lcpr case=start
// [1]\n3\n1\n
// @lcpr case=end

 */
