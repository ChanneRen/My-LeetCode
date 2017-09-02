
/*
	problem:	Jump Game II
	difficulty:	hard
	description:	Given an array of non-negative integers, you are initially positioned at the first index of the array.
    			Each element in the array represents your maximum jump length at that position.
			Your goal is to reach the last index in the minimum number of jumps.
			For example: Given array A = [2,3,1,1,4]
			The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
	note:		You can assume that you can always reach the last index.
  	tags:		Array, greedy
	
	solution:	An easy-to-understand but effective algorithm: Greedy
			Get the furthest position at each step and update the index.
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), res = 0, idx = 0;
        while(idx < n - 1)
        {
            res++;
            if(idx + nums[idx] >= n - 1)    return res;
            int tmp = idx;
            for(int i = idx + 1; i <= idx + nums[idx]; ++i)
                if(i + nums[i] > tmp + nums[tmp])
                    tmp = i;
            idx = tmp;
        }
        return res;
    }
};
