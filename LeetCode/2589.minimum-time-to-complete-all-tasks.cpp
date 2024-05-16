/*
 * @lc app=leetcode.cn id=2589 lang=cpp
 * @lcpr version=30202
 *
 * [2589] 完成所有任务的最少时间
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
    int findMinimumTime(vector<vector<int>> &tasks)
    {
        vector<bool> visited(2001, false);
        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        for (auto task : tasks)
        {
            int begin = task[0];
            int end = task[1];
            int duration = task[2];
            for (int i = begin; i <= end; i++)
            {
                if (duration && visited[i])
                    duration--;
            }
            if (duration == 0)
                continue;
            else
            { // 需要占用没有程序的时间
                cout << duration << endl;
                while (duration)
                {
                    if (visited[end] == false)
                    {
                        duration--;
                        visited[end] = true;
                    }
                    end--;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 2001; i++)
            if (visited[i])
            {
                // cout << i << endl;
                ans++;
            }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,3,1],[4,5,1],[1,5,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,2],[2,5,3],[5,6,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,18,5],[3,15,1]]\n
// @lcpr case=end

 */
