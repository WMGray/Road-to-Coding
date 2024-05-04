/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 * @lcpr version=30122
 *
 * [1652] 拆炸弹
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        // 分两种情况
        // k为负的直接变正
        bool flag = k < 0 ? true : false;
        if (flag)
        {
            k = abs(k);
            reverse(code.begin(), code.end());
        }

        int n = code.size();
        vector<int> dp(n); // 前缀和
        dp[0] = code[0];
        for (int i = 1; i < n; i++)
            dp[i] = code[i] + dp[i - 1];
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            // 确认左右边界
            int right = i + k;
            if (right > n - 1) // 超出右边界
            {
                ans[i] = (dp[n - 1] - dp[i] + dp[right - n]);
            }
            else
                ans[i] = dp[right] - dp[i];
        }
        if (flag)
            reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,7,1,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,4,9,3]\n-2\n
// @lcpr case=end

 */
