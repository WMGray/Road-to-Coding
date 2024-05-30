/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 * @lcpr version=30202
 *
 * [1673] 找出最具竞争力的子序列
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
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans; // 创建一个单调递减栈
                         /*
                         只有比栈顶元素大的元素才能直接进栈，否则需要先将栈中比当前元素大的元素出栈，再将当前元素入栈。
                         */
        // cout << " ------- " << endl;
        for (int i = 0; i < n; i++)
        {

            // 出栈 -- 比当前元素大的
            while (!ans.empty() && ans.back() > nums[i] && ans.size() + (n - i) > k)
                ans.pop_back();
            ans.push_back(nums[i]);
        }
        // for (auto v : ans)
        //     cout << v << " ";
        // cout << endl;
        ans.resize(k);
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,5,2,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3,3,5,4,9,6]\n4\n
// @lcpr case=end


// @lcpr case=start
// [71,18,52,29,55,73,24,42,66,8,80,2]\n3\n
// @lcpr case=end

 */
