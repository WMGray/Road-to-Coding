/*
 * @lc app=leetcode.cn id=2981 lang=cpp
 * @lcpr version=30202
 *
 * [2981] 找出出现至少三次的最长特殊子字符串 I
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
    int maximumLength(string s)
    {
        // 定义一个哈希表用于存放数据
        unordered_map<string, int> mm;
        int n = s.size();
        int ans = -1;
        for (int left = 0; left < n;)
        {
            // if (s[left] == '\x00')
            //     break;
            int right = left;
            while (right < n && s[right] == s[left])
                right++;
            // 相同长度的为  j - i + 1 个字符
            // 修改哈希表
            int m = right - left;
            // cout << m << endl;
            for (int i = 1; i <= m; i++)
            {
                string tmp_s(i, s[left]);
                mm[tmp_s] += m - i + 1;
            }
            left = right;
        }
        for (auto &[k, v] : mm)
        {
            if (v >= 3)
                ans = max(ans, int(k.size()));
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

// @lcpr case=start
// "abcdef"\n
// @lcpr case=end

// @lcpr case=start
// "abcaba"\n
// @lcpr case=end

 */
