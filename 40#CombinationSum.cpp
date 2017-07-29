/*
	problem:	Combination Sum
	difficulty:	medium
	description:	Given a set of candidate numbers (C) (without duplicates) and a target number (T),
    			find all unique combinations in C where the candidate numbers sums to T.
			Each number in C may only be used once in the combination.
	note:		All numbers (including target) will be positive integers.
			The solution set must not contain duplicate combinations.
  	tags:		Array, Backtracking
	
	solution:	Just the same as problem #Combination Sum# :
			1.find the sum of the numbers, so sort the array at first will be more easy;
			2.as the array is sorted now, if the target is less than the first, or the minimum number, we can pruning;
			3.any number in array can be used many times and solutions are not allowed duplicated ones, so set an index to avoid this.
			Compared to probelm #Combination Sum#, the only difference is that each number in the array can be used only ONCE!
			Just change the INDEX and add a judgement for index to filter duplicate numbers.
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
        for(int i = idx; i < candidates.size();)
        {
            if(target < candidates[i])  break;
            cur.push_back(candidates[i]);
            resolve(res, candidates, cur, i + 1, target - candidates[i]);
            while(++i < candidates.size() && candidates[i] == candidates[i - 1]);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        resolve(res, candidates, cur, 0, target);
        return res;
    }
};
