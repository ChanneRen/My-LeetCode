/*
	problem:	Combination Sum
	difficulty:	medium
	description:	Given a set of candidate numbers (C) (without duplicates) and a target number (T),
    			find all unique combinations in C where the candidate numbers sums to T.
			The same repeated number may be chosen from C unlimited number of times.
	note:		All numbers (including target) will be positive integers.
			The solution set must not contain duplicate combinations.
  	tags:		Array, Backtracking
	
	solution:	Approach with backtracking algorithm:
			1.find the sum of the numbers, so sort the array at first will be more easy;
			2.as the array is sorted now, if the target is less than the first, or the minimum number, we can pruning;
			3.any number in array can be used many times and solutions are not allowed duplicated ones, so set an index to avoid this.
*/

class Solution {
public:
    void resolve(vector<vector<int>> &res, vector<int> candidates, vector<int> cur, int idx, int target)
    {
        if(target == 0)
        {
            res.push_back(cur);
            return;
        }
        for(int i = idx; i < candidates.size(); ++i)
        {
            if(target < candidates[i])  break;
            cur.push_back(candidates[i]);
            resolve(res, candidates, cur, i, target - candidates[i]);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        resolve(res, candidates, cur, 0, target);
        return res;
    }
};
