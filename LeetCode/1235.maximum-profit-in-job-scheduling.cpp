/*
 * @lc app=leetcode.cn id=1235 lang=cpp
 * @lcpr version=30122
 *
 * [1235] 规划兼职工作
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
    long long max_salary = 0;
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++)
        {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int> &job1, const vector<int> &job2) -> bool
             { return job1[1] < job2[1]; });
        vector<long long> dp(n + 1);
        dp[0] = 0;
        // dp[i]: 前i份工作可以得到的最大报酬数
        // 来个前缀和记录
        for (int i = 1; i <= n; i++)
        {
            int k = upper_bound(jobs.begin(), jobs.begin() + i - 1,
                                jobs[i - 1][0],
                                [&](int st, const vector<int> &job) -> bool
                                { return st < job[1]; }) -
                    jobs.begin();
            // 记录满足jobs[i - 1][0] 的个数
            dp[i] = max(dp[i - 1],               // 不做第i - 1份工作
                        jobs[i - 1][2] + dp[k]); // 做第i - 1份工作
        }
        return dp[n];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,3]\n[3,4,5,6]\n[50,10,40,70]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,6]\n[3,5,10,6,9]\n[20,20,100,70,60]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n[2,3,4]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,4,8,2]\n[5,5,5,10,8]\n[1,2,8,10,4]\n
// @lcpr case=end

 */
