/*
 * @lc app=leetcode.cn id=3099 lang=golang
 * @lcpr version=30204
 *
 * [3099] 哈沙德数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func sumOfTheDigitsOfHarshadNumber(x int) int {
	str := strconv.Itoa(x)
	// fmt.Println(str)
	num := 0
	for _, s := range str {
		// fmt.Println(s, int(s)-48)
		num += int(s) - 48
	}
	// fmt.Println(x, num)
	if x%num == 0 {
		return num
	}
	return -1
}

// @lc code=end

/*
// @lcpr case=start
// 18\n
// @lcpr case=end

// @lcpr case=start
// 23\n
// @lcpr case=end

*/

