/*
 * @lc app=leetcode.cn id=2105 lang=cpp
 * @lcpr version=30201
 *
 * [2105] 给植物浇水 II
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
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
    {
        int tmp_left = capacityA, tmp_right = capacityB;
        int left = 0, right = plants.size() - 1;
        int res = 0;
        while (left < right)
        {
            if (tmp_left >= plants[left])
            {
                tmp_left -= plants[left];
            }
            else
            { // 回去打水
                tmp_left = capacityA - plants[left];
                res++;
            }
            if (tmp_right >= plants[right])
            {
                tmp_right -= plants[right];
            }
            else
            { // 回去打水
                tmp_right = capacityB - plants[right];
                res++;
            }
            left++;
            right--;
        }
        // 相遇了
        if (left == right) // 相遇
        {
            if (tmp_left >= plants[left] || tmp_right >= plants[left])
                return res;
            else
                return res + 1;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,2,3,3]\n5\n5\n
// @lcpr case=end

// @lcpr case=start
// [2,2,3,3]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n10\n8\n
// @lcpr case=end

// @lcpr case=start
// [726,739,934,116,643,648,473,984,482,85,850,806,146,764,156,66,186,339,985,237,662,552,800,78,617,933,481,652,796,594,151,82,183,241,525,221,951,732,799,483,368,354,776,175,974,187,913,842]\n1439\n1207\n
// @lcpr case=end

 */
