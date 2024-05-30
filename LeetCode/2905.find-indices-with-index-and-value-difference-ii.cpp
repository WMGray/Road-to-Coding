/*
 * @lc app=leetcode.cn id=2905 lang=cpp
 * @lcpr version=30202
 *
 * [2905] 找出满足差值条件的下标 II
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
    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
    {
        int n = nums.size();
        int min_idx = 0, max_idx = 0;
        if (indexDifference > n)
            return {-1, -1};
        for (int left = 0, right = indexDifference; right < n; left++, right++)
        {
            // 更新最小值最大值索引
            if (nums[min_idx] > nums[left])
                min_idx = left;
            if (nums[max_idx] < nums[left])
                max_idx = left;
            // 比较
            if (abs(nums[right] - nums[max_idx]) >= valueDifference)
            {
                return {right, max_idx};
            }
            if (abs(nums[right] - nums[min_idx]) >= valueDifference)
            {
                return {right, min_idx};
            }
        }
        return {-1, -1};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,1,4,1]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n0\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n2\n4\n
// @lcpr case=end

 */
