/*
 * @lc app=leetcode.cn id=1813 lang=cpp
 * @lcpr version=30122
 *
 * [1813] 句子相似性 III
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
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        int s1_length = sentence1.size();
        int s2_length = sentence2.size();

        if (s1_length > s2_length)
        {
            // 保证s1 是短字符串
            swap(sentence1, sentence2);
            swap(s1_length, s2_length);
        }
        // 前面
        int i = s1_length - 1, j = s2_length - 1;
        while (i >= 0 && j >= 0)
        {
            if (sentence1[i] == sentence2[j])
            {
                i--;
                j--;
            }
            else
                break;
        }
        if (i == -1 && (j == -1 || sentence2[j] == ' '))
            return true;

        // 后面
        i = 0, j = 0;
        while (i < s1_length && j < s2_length)
        {
            if (sentence1[i] == sentence2[j])
            {
                i++;
                j++;
            }
            else
                break;
        }
        if (i == s1_length && (j == s2_length || sentence2[j] == ' '))
            return true;

        // 中间
        i = 0, j = 0;
        while (i < s1_length && j < s2_length)
        {
            if (sentence1[i] == sentence2[j])
            {
                i++;
                j++;
            }
            else
                break;
        }
        i--;
        while (i >= 0 && sentence1[i] != ' ')
            i--;
        int a = i;
        i = s1_length - 1, j = s2_length - 1;
        while (i >= 0 && j >= 0)
        {
            if (sentence1[i] == sentence2[j])
            {
                i--;
                j--;
            }
            else
                break;
        }
        i++;
        while (i < s1_length && sentence1[i] != ' ')
            i++;
        cout << a << "  " << i;
        if (i <= a)
            return true;
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "My name is Haley"\n"My Haley"\n
// @lcpr case=end

// @lcpr case=start
// "of"\n"A lot of words"\n
// @lcpr case=end

// @lcpr case=start
// "Eating right now"\n"Eating"\n
// @lcpr case=end

// @lcpr case=start
// "Luky"\n"Lucccky"\n
// @lcpr case=end

 */
