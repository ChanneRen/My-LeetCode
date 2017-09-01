/*
	problem:	Permutations
	difficulty:	medium
	description:	Given a collection of distinct numbers, return all possible permutations. 
			For example, [1,2,3] have the following permutations:
				[
				  [1,2,3],
				  [1,3,2],
				  [2,1,3],
				  [2,3,1],
				  [3,1,2],
				  [3,2,1]
				]
  	tags:		Array, BackTracking
	
	solution:	It is easy to solve it with recursive method.
*/

class Solution {
public:
    void permute(vector<vector<int>>& res, vector<int>& nums, int index)
    {
        if(index == nums.size())
            res.push_back(nums);
        else
        {
            for(int i = index; i < nums.size(); ++i)
            {
                swap(nums[i], nums[index]);
                permute(res, nums, index + 1);
                swap(nums[i], nums[index]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(res, nums, 0);
        return res;
    }
};
