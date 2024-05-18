/*
 * @lc app=leetcode.cn id=826 lang=cpp
 * @lcpr version=30202
 *
 * [826] 安排工作以达到最大收益
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
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int n = difficulty.size();
        int m = worker.size();
        // zip
        vector<vector<int>> zip(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            zip[i][0] = difficulty[i];
            zip[i][1] = profit[i];
        }
        // 对zip进行排序
        sort(zip.begin(), zip.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });
        // 对worker进行排序
        sort(worker.begin(), worker.end());
        int ans = 0, cur_max = 0;
        if (worker[m - 1] < zip[0][0])
        {
            return 0;
        }
        // 先找到满足难度的第一个人
        int w_pos = 0, p_pos = 0;
        while (worker[w_pos] < zip[0][0])
            w_pos++;
        while (w_pos < m)
        {
            // 找到满足w_pos 的最大利润
            while (p_pos < n)
            {
                if (worker[w_pos] >= zip[p_pos][0]) // 能完成工作
                {
                    if (cur_max < zip[p_pos][1]) // 更新最大利润
                        cur_max = zip[p_pos][1];
                    p_pos++;
                }
                else
                    break;
            }
            ans += cur_max;
            w_pos++;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,4,6,8,10]\n[10,20,30,40,50]\n[4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// [85,47,57]\n[24,66,99]\n[40,25,25]\n
// @lcpr case=end

 */
