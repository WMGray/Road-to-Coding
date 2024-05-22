/*
 * @lc app=leetcode.cn id=2225 lang=cpp
 * @lcpr version=30202
 *
 * [2225] 找出输掉零场或一场比赛的玩家
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
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, pair<int, int>> dp;
        for (auto match : matches)
        {
            dp[match[0]].first++;  // 胜利
            dp[match[1]].second++; // 失败
        }
        vector<vector<int>> ans(2);
        for (auto &[k, v] : dp)
        {
            if (v.second == 0) // 没有输掉任何比赛
                ans[0].push_back(k);
            else if (v.second == 1) // 输掉一场比赛
                ans[1].push_back(k);
            else
                continue;
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,3],[1,3],[5,4],[6,4]]\n
// @lcpr case=end

 */
