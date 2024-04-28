/*
 * @lc app=leetcode.cn id=789 lang=cpp
 * @lcpr version=30122
 *
 * [789] 逃脱阻碍者
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
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        // 先算最少需要多少步
        int need_walk = abs(target[0]) + abs(target[1]); // 这是逃脱最短时间
        // 记录ghost到这个最短的路径
        vector<int> ghost_walk(ghosts.size(), 0);
        for (int i = 0; i < ghosts.size(); i++)
            ghost_walk[i] = abs(target[0] - ghosts[i][0]) + abs(target[1] - ghosts[i][1]);
        // 取出最小的
        auto min_ghost_walk = min_element(ghost_walk.begin(), ghost_walk.end());
        cout << endl;
        cout << (int)*min_ghost_walk;
        if ((int)*min_ghost_walk <= need_walk)
            return false; // 逃不掉的
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,0],[0,3]]\n[0,1]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0]]\n[2,0]\n
// @lcpr case=end

// @lcpr case=start
// [[2,0]]\n[1,0]\n
// @lcpr case=end

 */
