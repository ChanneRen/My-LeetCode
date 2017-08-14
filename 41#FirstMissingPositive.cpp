/*
	problem:	First Missing Positive
	difficulty:	hard
	description:	Given an unsorted integer array, find the first missing positive integer. 
			For example, Given [1,2,0] return 3, and [3,4,-1,1] return 2.
			Your algorithm should run in O(n) time and uses constant space.
  	tags:		Array
	
	solution:	I first think to use #bitmap# to record each number that occurs in the array. Then get target from bitmap.
			But the size of the array is not fixed and it seems to use much extra space.
			In fact for integer array, specially consecutive one, it's always useful to take use of index with number itself.
			Such as that array[index] = index or array[index] = index + 1.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), idx = 0;
        while(idx < n)
        {
            if(nums[idx] == idx + 1) {idx++; continue;}
            if(nums[idx] > 0 && nums[idx] <= n && nums[idx] != nums[nums[idx] - 1])
            {
                int t = nums[idx];
                nums[idx] = nums[t - 1];
                nums[t - 1] = t;
            }
            else
                ++idx;
        }
        for(idx = 0; idx < n; ++idx)
            if(nums[idx] != idx + 1)
                return idx + 1;
        return n + 1;
    }
};
