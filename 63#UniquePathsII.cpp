
/*
	problem:	Unique Paths II
	difficulty:	medium
	description:	Follow up for "Unique Paths": 
			Now consider if some obstacles are added to the grids. How many unique paths would there be?
			An obstacle and empty space is marked as 1 and 0 respectively in the grid.
	note:		m and n will be at most 100.
  	tags:		Array, Dynamic Programming
	
	solution:	The same way as #Unique Paths# :
			As the robot can only move either down or right, the number of paths for any point (x, y) that the robot to reach is
			f(x, y) = f(x -1, y) + f(x, y - 1) where f(x, y) means the number of paths to get to (x, y) from start
			So, just traverse each point from top-left to bottom-right. Notice that any point at top row and column the number of paths is one.
			
			What we need to change is to add a judgement, especially for first row and column of the result for each point.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int i = 0;
        while(i < n && obstacleGrid[0][i] != 1){dp[0][i] = 1; ++i;}
        i = 0;
        while(i < m && obstacleGrid[i][0] != 1){dp[i][0] = 1; ++i;}
        for(i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
            {
                if(obstacleGrid[i][j] != 1)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        return dp[m - 1][n - 1];
    }
};
