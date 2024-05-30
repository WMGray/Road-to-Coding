/*
 * @lc app=leetcode.cn id=2831 lang=cpp
 * @lcpr version=30202
 *
 * [2831] 找出最长等值子数组
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
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        // 创建一个下标数组用于排序
        int n = nums.size();
        unordered_map<int, vector<int>> idx_list;
        for (int i = 0; i < n; i++)
        {
            idx_list[nums[i]].push_back(i); // nums[i] -- [x, x, ...]
        }
        int ans = 0; // 存放最大值
        for (auto &[num, list] : idx_list)
        {
            int n = list.size();
            for (int left = 0, right = 0;
                 right < n; right++)
            {
                // 找出[left, right]满足的left
                while (list[right] - list[left] - (right - left) > k)
                    left++;
                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,2,3,1,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,2,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,1,2,1,1,1,2,3,4,1,1,1]\n2\n
// @lcpr case=end

 */
