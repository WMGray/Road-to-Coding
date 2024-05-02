/*
 * @lc app=leetcode.cn id=2462 lang=cpp
 * @lcpr version=30122
 *
 * [2462] 雇佣 K 位工人的总代价
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        long long res = 0;
        int n = costs.size();
        if (n <= 2 * candidates)
        {
            sort(costs.begin(), costs.end());
            for (int i = 0; i < k; i++)
                res += costs[i];
            return res;
        }
        // 建立两个堆
        priority_queue<int, vector<int>, greater<>> left, right;
        for (int i = 0; i < candidates; i++) // 初始化最小堆
        {
            left.push(costs[i]);
            right.push(costs[n - 1 - i]);
        }
        int i = candidates - 1, j = n - candidates; // 记录边界
        while (k--)
        {
            // cout << "Find: " << k << endl;
            if (j - i <= 1) // 接近了
            {
                while (!right.empty())
                {
                    left.push(right.top());
                    right.pop();
                }
                k++;
                while (k--)
                {
                    // cout << "Find: " << k << endl;
                    // cout << "Select: " << left.top() << endl;
                    res += left.top();
                    left.pop();
                }
                return res;
            }
            else
            {
                if (left.top() > right.top())
                {
                    // cout << "Select: " << right.top() << endl;
                    res += right.top();
                    right.pop();
                    right.push(costs[--j]);
                }
                else
                {
                    // cout << "Select: " << left.top() << endl;
                    res += left.top();
                    left.pop();
                    left.push(costs[++i]);
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [17,12,10,2,7,2,11,20,8]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,1]\n3\n3\n
// @lcpr case=end

// @lcpr case=start
// [31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58]\n11\n2\n
// @lcpr case=end

 */
