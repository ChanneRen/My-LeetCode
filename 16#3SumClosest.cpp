/*
	problem:	3 Sum Closest
	difficulty:	medium
	description:	Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
			Return the sum of the three integers. You may assume that each input would have exactly one solution.
	note:		The solution set must not contain duplicate triplets.
  	tags:		Array, Two Pointers
	
	solution:	the same idea as problem #3Sum#
			Sort the array, and take each number as the basic one, use two pointers to get the closest sum.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), cur = 0, res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; ++i)
        {
            int l = i + 1, r = n - 1;
            while(l < r)
            {
                cur = nums[i] + nums[l] + nums[r];
                if(cur == target)
                    return target;
                else if(abs(cur - target) < abs(res - target))
                    res = cur;
                if(cur < target)    ++l;
                else    --r;
            }
        }
        return res;
    }
};
