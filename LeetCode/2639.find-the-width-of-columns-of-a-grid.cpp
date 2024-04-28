/*
 * @lc app=leetcode.cn id=2639 lang=cpp
 * @lcpr version=30122
 *
 * [2639] 查询网格图中每一列的宽度
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
    vector<int> res;
    vector<int> findColumnWidth(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            int tmp = 0;
            for (int j = 0; j < m; j++)
                tmp = max(tmp, int(to_string(grid[j][i]).size()));
            res.push_back(tmp);
        }
        for (auto value : res)
            cout << value << "  ";
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1],[22],[333]]\n
// @lcpr case=end

// @lcpr case=start
// [[-15,1,3],[15,7,12],[5,6,-2]]\n
// @lcpr case=end

 */
