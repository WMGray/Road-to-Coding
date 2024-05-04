/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 * @lcpr version=30122
 *
 * [1248] 统计「优美子数组」
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
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0] % 2 != 0 ? 1 : 0;
        for (int i = 1; i < nums.size(); i++)
            dp[i] = nums[i] % 2 != 0 ? dp[i - 1] + 1 : dp[i - 1];
        if (dp[nums.size() - 1] < k)
            return 0;
        unordered_map<int, int> m;
        m[0] = 1;
        int res = 0;
        for (auto value : dp)
        {
            m[value]++;
            if (value >= k)
                res += m[value - k];
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,4,6]\n1\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,1,2,2,1,2,2,2]\n2\n
// @lcpr case=end

 */
