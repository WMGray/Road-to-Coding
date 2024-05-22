/*
 * @lc app=leetcode.cn id=1542 lang=cpp
 * @lcpr version=30202
 *
 * [1542] 找出最长的超赞子字符串
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
    // int check(string s)
    // {
    //     unordered_map<char, int> char_freq;
    //     for (auto ch : s) // 计算频次
    //         char_freq[ch]++;
    //     // 根据频次查看
    //     int s_num = 0;
    //     for (auto &[k, v] : char_freq)
    //     {
    //         if (v % 2 == 1)
    //             s_num++;
    //     }
    //     // 此时， 奇数个字符只有0 / 1个，必定是回文
    //     return s_num;
    // }
    int longestAwesome(string s)
    {
        int n = s.size();

        int best = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = i; j < n; j++)
            {
                if (best > j - i + 1) // 是回文也不行
                    continue;
                int s_num = check(s.substr(i, j - i + 1));
                if (s_num <= 1) // 回文
                    best = max(best, j - i + 1);
                else // 不是回文，有s_num个奇数 --> 至少往后挪 s_num - 1 个字符
                    j += s_num - 1 - 1;
            }
        return best;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "3242415"\n
// @lcpr case=end

// @lcpr case=start
// "12345678"\n
// @lcpr case=end

// @lcpr case=start
// "213123"\n
// @lcpr case=end

// @lcpr case=start
// "00"\n
// @lcpr case=end

// @lcpr case=start
// "782302122805691033901177183111699635961604489883121712082139681866909906852252580396287070826596004679229522009490687629060803597588313093612825139333850842446140521476928738377786450988411174000546526740939422468148635482519351197732289287001062051397463018460807687568256389298876320143875922310887799143592172453017285788876736444773845634979372911241989615371474019759941270734663228990559056155967412726399574492647371813441193622292606731065844633123589338921370953535577438000530704596076308831439335721796891046444530491337367798094351398588102029655192582961587187172626826411560401450189986478023314489951539999139974365562186957776297755962229414292948836534636019517654867109414857848217230972205125912698155127423241805366877530170447508427807303074136458442047425771741497425660964709474459207639775385355925584676689737531558642636223161269972397819022381329080149356312961270290461020614446440622239036709819404575747578206596"\n
// @lcpr case=end
 */
