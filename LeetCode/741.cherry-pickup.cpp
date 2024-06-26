/*
 * @lc app=leetcode.cn id=741 lang=cpp
 * @lcpr version=30122
 *
 * [741] 摘樱桃
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
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<vector<int>>> f(n * 2 - 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        f[0][0][0] = grid[0][0];
        for (int k = 1; k < n * 2 - 1; ++k)
        {
            for (int x1 = max(k - n + 1, 0); x1 <= min(k, n - 1); ++x1)
            {
                int y1 = k - x1;
                if (grid[x1][y1] == -1)
                {
                    continue;
                }
                for (int x2 = x1; x2 <= min(k, n - 1); ++x2)
                {
                    int y2 = k - x2;
                    if (grid[x2][y2] == -1)
                    {
                        continue;
                    }
                    int res = f[k - 1][x1][x2]; // 都往右
                    if (x1)
                    {
                        res = max(res, f[k - 1][x1 - 1][x2]); // 往下，往右
                    }
                    if (x2)
                    {
                        res = max(res, f[k - 1][x1][x2 - 1]); // 往右，往下
                    }
                    if (x1 && x2)
                    {
                        res = max(res, f[k - 1][x1 - 1][x2 - 1]); // 都往下
                    }
                    res += grid[x1][y1];
                    if (x2 != x1)
                    { // 避免重复摘同一个樱桃
                        res += grid[x2][y2];
                    }
                    f[k][x1][x2] = res;
                }
            }
        }
        return max(f.back().back().back(), 0);
    }
};

// @lc code=end

/*
// @lcpr case=start
// [[0,1,-1],[1,0,-1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,-1],[1,-1,1],[-1,1,1]]\n
// @lcpr case=end

 */
