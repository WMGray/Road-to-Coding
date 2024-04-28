/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 * @lcpr version=30122
 *
 * [1017] 负二进制转换
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
    string res;
    string baseNeg2(int n)
    {
        if (n == 0)
            return "0";
        if (n == 1)
            return "1";
        while (n != 0)
        {
            int a = n / -2;
            int b = n - a * (-2);
            if (b < 0)
            {
                a++;
                b += 2;
            }
            res = to_string(b) + res;
            n = a;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */
