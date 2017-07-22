
/*
	problem:	Minimum Path Sum
	difficulty:	medium
	description:	Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path. 
	note:		You can only move either down or right at any point in time.
  	tags:		Array, Dynamic Programming
	
	solution:	The same as problem #Unique Paths#
			f(x, y) = f(x -1, y) + f(x, y - 1) where f(x, y) means the minimum path sum to get to (x, y) from start
			The difference between #Unique Paths# is the way to process the first row and column because we need to calculate sum not paths.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)  return 0;
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[0][1] = 0;
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        return dp[m][n];
    }
};
