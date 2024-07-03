/*
 * @lc app=leetcode.cn id=3115 lang=golang
 * @lcpr version=30204
 *
 * [3115] 质数的最大距离
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func maximumPrimeDifference(nums []int) int {
	n := len(nums)
	left, right := 0, n-1
	zhishu := make([]bool, 101)
	zhishu[1] = false
	zhishu[2] = true
	for i := 3; i < 101; i++ {
		if i%2 == 0 {
			// i 为奇数， i + 1 为偶数，偶数除2全非质数
			zhishu[i] = false
			continue
		}
		zhishu[i] = true
		for j := 2; j <= 10 && j < i; j++ {
			if (i)%j == 0 {
				zhishu[i] = false
				break
			}
		}
	}
	// for idx, v := range
	for ; left < right; left++ {
		if zhishu[nums[left]] {
			break
		}
	}
	for ; right > left; right-- {
		if zhishu[nums[right]] {
			break
		}
	}

	return right - left
}

// @lc code=end

/*
// @lcpr case=start
// [4,2,9,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,8,2,8]\n
// @lcpr case=end

*/

