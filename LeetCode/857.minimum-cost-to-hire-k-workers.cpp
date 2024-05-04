/*
 * @lc app=leetcode.cn id=857 lang=cpp
 * @lcpr version=30122
 *
 * [857] 雇佣 K 名工人的最低成本
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
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();
        vector<vector<double>> AAA; // 性价比
        for (int i = 0; i < n; i++)
        {
            AAA.push_back({(double)wage[i],
                           (double)quality[i],
                           (double)wage[i] / quality[i]});
        }
        sort(AAA.begin(), AAA.end(), [&](vector<double> &a, vector<double> &b)
             { return a[2] < b[2]; }); // 按照性价比排好序了
        for (auto row : AAA)
        {
            for (auto value : row)
                cout << value << "  ";
            cout << endl;
        }
        // 用大顶堆记录quality， 只需要替换掉最大的就行
        priority_queue<double, vector<double>, less<>> pq;
        double sum_q = 0;
        for (int i = 0; i < k; i++) // 第一个结果
        {
            pq.push(AAA[i][1]);
            sum_q += AAA[i][1];
        }
        double ans = sum_q * AAA[k - 1][2];
        cout << "First:  sum_q: " << sum_q << "  r: " << AAA[k - 1][2] << endl;
        // 现在遍历找最小的
        for (int i = k; i < n; i++) // 后面的工人 r 值更大, 只有小的sum_q 才可取胜
        {
            if (AAA[i][1] < pq.top()) // 当前员工工作量更小
            {
                sum_q -= pq.top() - AAA[i][1]; // 更新目前的sum_q, 会更小
                pq.pop();
                pq.push(AAA[i][1]);
                ans = min(ans, sum_q * AAA[i][2]);
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,20,5]\n[70,50,30]\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,1,10,10,1]\n[4,8,2,2,7]\n3\n
// @lcpr case=end

 */
