/*
 * @lc app=leetcode.cn id=2644 lang=cpp
 * @lcpr version=30202
 *
 * [2644] 找出可整除性得分最大的整数
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
    int maxDivScore(vector<int> &nums, vector<int> &divisors)
    {
        int max_d = INT32_MAX, max_ = -1;
        int m = divisors.size(), n = nums.size();
        for (int i = 0; i < m; i++)
        {
            int tmp = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[j] % divisors[i] == 0)
                    tmp++;
            }
            if (tmp > max_)
            {
                max_ = tmp;
                max_d = divisors[i];
            }
            else if (tmp == max_)
            {
                max_d = min(max_d, divisors[i]);
            }
        }
        return max_d;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,7,9,3,9]\n[5,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [20,14,21,10]\n[5,7,5]\n
// @lcpr case=end

// @lcpr case=start
// [12]\n[10,16]\n
// @lcpr case=end

// @lcpr case=start
//[73,13,20,6]\n[56,75,83,26,24,53,56,61]\n
// @lcpr case=end
 */
