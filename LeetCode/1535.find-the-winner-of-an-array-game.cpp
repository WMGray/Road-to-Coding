/*
 * @lc app=leetcode.cn id=1535 lang=cpp
 * @lcpr version=30202
 *
 * [1535] 找出数组游戏的赢家
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
    int getWinner(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k >= n - 1) // 肯定要挑出最大的
            return *max_element(arr.begin(), arr.end());
        int a = 0; // 分别记录胜利次数
        // 模拟吧
        while (true)
        {
            // 这一步比较
            if (arr[0] > arr[1]) // a 胜利
            {
                a++;
                int tmp = arr[1];
                arr.erase(arr.begin() + 1); // 删除
                arr.push_back(tmp);         // 加入
            }
            else
            {
                // b 胜利， b是新来的，初始为0 --> a = 1
                a = 1;
                int tmp = arr[0];
                arr.erase(arr.begin()); // 删除
                arr.push_back(tmp);     // 加入
            }
            if (a >= k)
                break;
        }
        return arr[0];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,3,5,4,6,7]\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,9,8,2,3,7,6,4,5]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,11,22,33,44,55,66,77,88,99]\n1000000000\n
// @lcpr case=end

 */
