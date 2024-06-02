/*
 * @lc app=leetcode.cn id=2928 lang=cpp
 * @lcpr version=30203
 *
 * [2928] 给小朋友们分糖果 I
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
    int ans = 0;
    void tracebrace(int n, int limit, int child_idx)
    {
        if (child_idx == 3)
        {
            cout << n << endl;
            ans++;
            return;
        }
        int min_ = max(n - (3 - child_idx) * limit, 0);
        int max_ = min(n, limit);
        for (int i = min_; i <= max_; i++)
        {
            // cout << child_idx << ": " << i << "  ";
            cout << i << "  ";
            tracebrace(n - i, limit, child_idx + 1);
        }
    }
    int distributeCandies(int n, int limit)
    {
        tracebrace(n, limit, 1);
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n2\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */
