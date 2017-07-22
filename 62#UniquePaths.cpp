/*
	problem:	Unique Paths
	difficulty:	medium
	description:	A robot is located at the top-left corner of a m x n grid. 
			The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid.
			How many possible unique paths are there?
	note:		m and n will be at most 100.
  	tags:		Array, Dynamic Programming
	
	solution:	As the robot can only move either down or right, the number of paths for any point (x, y) that the robot to reach is
			f(x, y) = f(x -1, y) + f(x, y - 1) where f(x, y) means the number of paths to get to (x, y) from start
			So, just traverse each point from top-left to bottom-right. Notice that any point at top row and column the number of paths is one.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; ++i)
            dp[i][1] = 1;
        for(int j = 1; j <= n; ++j)
            dp[1][j] = 1;
        for(int i = 2; i <= m; ++i)
        {
            for(int j = 2; j <= n; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        return dp[m][n];
    }
};
