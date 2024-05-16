// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=994 lang=cpp
 * @lcpr version=30201
 *
 * [994] 腐烂的橘子
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
    int orangesRotting(vector<vector<int>> &grid)
    {
        int total_apples = 0;
        queue<pair<int, int>> Q;
        int bad_apples = 0;
        // 遍历整个果园， 计算坏果，并添加到队列中
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0) // 有果子
                {
                    total_apples++;
                    if (grid[i][j] == 2)
                    {
                        Q.push({i, j});
                        bad_apples++; // 坏果子
                    }
                }
            }
        }
        // cout << "total_apples: " << total_apples << endl;
        // cout << "bad_apples " << bad_apples << endl;
        // 添加 -1 表示一层结束
        Q.push({-1, -1});
        // 统计完所有的坏果子了， BFS记录坏果子
        int depth = 0;     // 深度 -- 蔓延时间
        while (!Q.empty()) // 有坏果子就遍历
        {
            pair<int, int> cur_pair = Q.front(); // 取出当前节点
            Q.pop();
            if (cur_pair == make_pair(-1, -1)) // 当前层结束 --> 下一层添加结束
            {
                if (!Q.empty())
                {
                    Q.push({-1, -1});
                    depth++;
                }
                continue;
            }

            // 当前{i, j} 是坏果子，且层没有结束
            // 添加果子
            int i = cur_pair.first, j = cur_pair.second; // 取出i, j
            // 由于第一次已经添加完了所有的坏果子，不可能有孤立的坏果子没有加入
            if (i > 0 && grid[i - 1][j] == 1)
            { // 上
                Q.push({i - 1, j});
                grid[i - 1][j] = 2;
                bad_apples++;
            }
            if (i < m - 1 && grid[i + 1][j] == 1)
            { // 下
                Q.push({i + 1, j});
                grid[i + 1][j] = 2;
                bad_apples++;
            }
            if (j > 0 && grid[i][j - 1] == 1)
            {
                Q.push({i, j - 1});
                grid[i][j - 1] = 2;
                bad_apples++;
            }
            if (j < n - 1 && grid[i][j + 1] == 1)
            {
                Q.push({i, j + 1});
                grid[i][j + 1] = 2;
                bad_apples++;
            }
        }
        return total_apples == bad_apples ? depth : -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,1,1],[1,1,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,1],[0,1,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2]]\n
// @lcpr case=end

 */
