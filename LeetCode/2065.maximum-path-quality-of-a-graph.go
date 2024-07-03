/*
 * @lc app=leetcode.cn id=2065 lang=golang
 * @lcpr version=30204
 *
 * [2065] 最大化一张图中的路径价值
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func maximalPathQuality(values []int, edges [][]int, maxTime int) int {
	// 建立邻接表
	n := len(values)
	graph := make([][][2]int, n)
	for _, edge := range edges {
		x, y, z := edge[0], edge[1], edge[2]
		graph[x] = append(graph[x], [2]int{y, z})
		graph[y] = append(graph[y], [2]int{x, z})
	}

	visited := make([]bool, n)
	visited[0] = true
	ans := 0

	var dfs func(int, int, int)
	dfs = func(u, time, value int) {
		if u == 0 {
			ans = max(ans, value)
		}
		for _, e := range graph[u] {
			v, dist := e[0], e[1]
			if time+dist <= maxTime {
				if !visited[v] {
					visited[v] = true
					dfs(v, time+dist, value+values[v])
					visited[v] = false
				} else {
					dfs(v, time+dist, value)
				}
			}
		}
	}

	dfs(0, 0, values[0])
	return ans
}

// @lc code=end

/*
// @lcpr case=start
// [0,32,10,43]\n[[0,1,10],[1,2,15],[0,3,10]]\n49\n
// @lcpr case=end

// @lcpr case=start
// [5,10,15,20]\n[[0,1,10],[1,2,10],[0,3,10]]\n30\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n[[0,1,10],[1,2,11],[2,3,12],[1,3,13]]\n50\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2]\n[[1,2,10]]\n10\n
// @lcpr case=end

*/

