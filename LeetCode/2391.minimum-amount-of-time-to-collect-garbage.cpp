/*
 * @lc app=leetcode.cn id=2391 lang=cpp
 * @lcpr version=30201
 *
 * [2391] 收集垃圾的最少总时间
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
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        vector<int> dp(3, 0);  // M, P, G
        vector<int> pos(3, 0); // 三辆车的位置
        travel.insert(travel.begin(), 0);
        for (int i = 0; i < garbage.size(); i++)
        {
            // 到第i个垃圾堆
            unordered_map<char, int> m{
                {'M', 0},
                {'P', 0},
                {'G', 0}};
            for (auto value : garbage[i])
                m[value]++;
            if (m['M']) // 金属
            {
                for (int j = pos[0] + 1; j <= i; j++)
                    dp[0] += travel[j];
                pos[0] = i;      //  移动到i垃圾堆
                dp[0] += m['M']; // 收集垃圾
            }
            if (m['P']) // 纸张
            {
                for (int j = pos[1] + 1; j <= i; j++)
                    dp[1] += travel[j];
                pos[1] = i;      //  移动到i垃圾堆
                dp[1] += m['P']; // 收集垃圾
            }
            if (m['G']) // 玻璃
            {
                for (int j = pos[2] + 1; j <= i; j++)
                    dp[2] += travel[j];
                pos[2] = i;      //  移动到i垃圾堆
                dp[2] += m['G']; // 收集垃圾
            }
        }
        cout << "All time: M: " << dp[0] << " P: " << dp[1] << " G:  " << dp[2] << endl;
        int res = 0;
        for (auto value : dp)
            res += value;
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["G","P","GP","GG"]\n[2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// ["MMM","PGM","GP"]\n[3,10]\n
// @lcpr case=end

 */
