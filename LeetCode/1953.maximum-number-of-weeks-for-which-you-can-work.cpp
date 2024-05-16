/*
 * @lc app=leetcode.cn id=1953 lang=cpp
 * @lcpr version=30202
 *
 * [1953] 你可以工作的最大周数
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
#include <math.h>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    long long numberOfWeeks(vector<int> &milestones)
    {
        int n = milestones.size();
        int sum_ = 0;
        long long max_ = *max_element(milestones.begin(), milestones.end());

        // 其余工作共计所需周数
        long long rest = accumulate(milestones.begin(), milestones.end(), 0LL) - max_;
        return max_ <= rest ? rest + max_ : 2 * rest + 1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [5,7,5,7,9,7]\n
// @lcpr case=end

 */
