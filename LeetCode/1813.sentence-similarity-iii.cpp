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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<string> to_words(string S)
    {
        stringstream ss;
        vector<string> res;
        ss << S;
        string b;
        while (ss >> b)
            res.push_back(b);
        return res;
    }
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        if (sentence1.size() > sentence2.size())
            swap(sentence1, sentence2);
        vector<string> s1 = to_words(sentence1);
        vector<string> s2 = to_words(sentence2);
        int s1_len = s1.size(), s2_len = s2.size();
        int l = 0, r = 0;                    // 左右相等单词个数
        while (l < s1_len && s1[l] == s2[l]) // 左边相等个数
            l++;
        while (r < s1_len - l && s1[s1_len - 1 - r] == s2[s2_len - 1 - r]) // 减去左边相等的个数
            r++;
        return l + r == s1_len;
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
