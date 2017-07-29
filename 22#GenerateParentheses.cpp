
/*
	problem:	Generate Parentheses
	difficulty:	medium
	description:	Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
    			For example, given n = 3, a solution set is:
				[
				  "((()))",
				  "(()())",
				  "(())()",
				  "()(())",
				  "()()()"
				]
  	tags:		String, Backtracking
	
	solution:	Backtracking algorithm:
			Search one solution in all of the solution space:
				if reach the end, get one solution;
				if the path can move on, record and go on;
				if the path is blocked, pruning
*/

class Solution {
public:
    void recurSolve(vector<string> &res, string cur, int left, int right, int n)
    {
        if(cur.length() == 2 * n)
        {
            res.push_back(cur);
            return;
        }
        if(left < n)
            recurSolve(res, cur + "(", left + 1, right, n);
        if(right < left)
            recurSolve(res, cur + ")", left, right + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recurSolve(res, "", 0, 0, n);
        return res;
    }
};
