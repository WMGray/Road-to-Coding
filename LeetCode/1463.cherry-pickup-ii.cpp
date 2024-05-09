/*
 * @lc app=leetcode.cn id=1463 lang=cpp
 * @lcpr version=30122
 *
 * [1463] 摘樱桃 II
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
    int cherryPickup(vector<vector<int>> &grid)
    {
        // 机器人至少往下一格 --> 共走n步 自底向上 -- 递推
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> f(m + 1, vector<vector<int>>(n + 2, vector<int>(n + 2))); // y2, y11, y12 -- 表示 A 从 (y2, y11) 出发，B 从 (y2, y12) 出发，到达最后一行，可以得到的樱桃个数的最大值
        for (int i = m - 1; i >= 0; i--)
        {
            for (int y1 = 0; y1 < min(n, i + 1); y1++)
            {
                for (int y2 = max(y1 + 1, n - 1 - i); y2 < n; y2++)
                {
                    f[i][y1 + 1][y2 + 1] = max({
                                               f[i + 1][y1][y2],
                                               f[i + 1][y1][y2 + 1],
                                               f[i + 1][y1][y2 + 2],
                                               f[i + 1][y1 + 1][y2],
                                               f[i + 1][y1 + 1][y2 + 1],
                                               f[i + 1][y1 + 1][y2 + 2],
                                               f[i + 1][y1 + 2][y2],
                                               f[i + 1][y1 + 2][y2 + 1],
                                               f[i + 1][y1 + 2][y2 + 2],
                                           }) +
                                           grid[i][y1] + grid[i][y2];
                }
            }
        }
        return f[0][1][n];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1]]\n
// @lcpr case=end

 */
