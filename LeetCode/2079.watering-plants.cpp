/*
 * @lc app=leetcode.cn id=2079 lang=cpp
 * @lcpr version=30201
 *
 * [2079] 给植物浇水
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
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int res = 0;
        int n = plants.size();
        int cap = capacity;
        for (int i = -1; i < n - 1; i++)
        {
            if (cap >= plants[i + 1])
            {
                res++;
                cap -= plants[i + 1];
            }
            else
            { // 回去取水
                cap = capacity - plants[i + 1];
                res += 2 * (i + 1) + 1;
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,2,3,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,4,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n8\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4,2,1]\n6\n
// @lcpr case=end

 */
