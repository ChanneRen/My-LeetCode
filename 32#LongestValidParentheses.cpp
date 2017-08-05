/*
	problem:	Longest Valid Parentheses
	difficulty:	hard
	description:	Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring. 
			For "(()", the longest valid parentheses substring is "()", which has length = 2.
			Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
  	tags:		String, Dynamic Programming
	
	solution:	Dynamic Programming is quite effective for this problem:
			dp[i] means the longest valid parentheses from ith char to the first one.
			Here, notice that dp[i] must conclude ith char, which means 
				if s[i] cannot make a valid parentheses with some chars in front of it, then dp[i] = 0.
			In this way we can ensure that we get the longest valid parentheses is in a subtring not a sub-sequence.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), res = 0;
        vector<int> dp(n, 0);
        for(int i = 1; i < n; ++i)
        {
            if(s[i] == ')')
            {
                int j = i - 1 - dp[i - 1];
                if(j >= 0 && s[j] == '(')
                {
                    dp[i] = dp[i - 1] + 2;
                    if(j - 1 > 0)
                        dp[i] += dp[j - 1];
                }                 
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
