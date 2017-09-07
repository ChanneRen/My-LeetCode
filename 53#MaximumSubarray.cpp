/*
	problem:	Maximum Subarray
	difficulty:	hard
	description:	Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
    			For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
			the contiguous subarray [4,-1,2,1] has the largest sum = 6.
  	tags:		Array, Dynamic and Programming, Divide and Conquer
	
	solution:	A classical problem : just need to judge if current sum is less than zero, if so reset to zero.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, cur = 0;
        for(auto num : nums)
        {
            cur += num;
            if(res < cur)
                res = cur;
            if(cur < 0)
                cur = 0;
        }
        return res;
    }
};
