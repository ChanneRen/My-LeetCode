/*
	problem:	4 Sum
	difficulty:	medium
	description:	Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?  
			Find all unique quadruplets in the array which gives the sum of target.
	note:		The solution set must not contain duplicate quadruplets.
  	tags:		Array, Two Pointers
	
	solution:	Almost the same as the problem #3 Sum#
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 4)   return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; ++i)
        {
            for(int j = i + 1; j < n - 2; ++j)
            {
                int l = j + 1, r = n - 1;
                while(l < r)
                {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum < target)    l++;
                    else if(sum > target)   r--;
                    else
                    {
                        res.push_back(vector<int> {nums[i], nums[j], nums[l], nums[r]});
                        while((l + 1) < r && nums[l + 1] == nums[l])  l++;
                        while((r - 1) > l && nums[r - 1] == nums[r])  r--;
                        l++;
                        r--;
                    }
                }
                while((j + 1) < n - 2 && nums[j + 1] == nums[j]) j++;
            }
            while((i + 1) < n - 3 && nums[i + 1] == nums[i])  i++;
        }
        return res;
    }
};
