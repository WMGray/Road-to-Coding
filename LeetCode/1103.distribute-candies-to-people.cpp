/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 * @lcpr version=30203
 *
 * [1103] 分糖果 II
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
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> ans(num_people);
        int last = 0;
        int pos = 0;
        for (int times = 0;; times++)
        {
            if (candies <= 0)
                break;
            for (pos = 0; pos < num_people; pos++)
            {
                int candy = times * num_people + pos + 1;
                ans[pos] += candy;
                candies -= candy;
                if (candies <= 0)
                    break;
            }
        }
        // 最后一个多加的剪掉
        ans[pos] += candies;
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 7\n4\n
// @lcpr case=end

// @lcpr case=start
// 10\n3\n
// @lcpr case=end

 */
