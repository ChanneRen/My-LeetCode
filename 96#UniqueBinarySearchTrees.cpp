/*
	problem:	Unique Binary Search Trees
	difficulty:	medium
	description:	Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
	tags:		Dynamic Programming
	
	solution:	For number 1 to n to construct BST, just consider this: 
			each number coulde be taken as root, and then the numbers could be paritioned as two groups, or called as subtrees.
			Take f(x) as the number of BSTs which make x as root, then f(x) = f(x - 1) * f(n - x).
			So, calculate f(x) from 1 to n recursively.
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 1; j <= i; ++j)
                dp[i] += dp[j - 1] * dp[i - j];
        }
        return dp[n];
    }
};
