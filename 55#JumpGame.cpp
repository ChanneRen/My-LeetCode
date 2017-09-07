/*
	problem:	Jump Game
	difficulty:	medium
	description:	Given an array of non-negative integers, you are initially positioned at the first index of the array.
    			Each element in the array represents your maximum jump length at that position.
			Determine if you are able to reach the last index.
			For example: Given array A = [2,3,1,1,4], return true.
				A = [3,2,1,0,4], return false.
  	tags:		Array, greedy
	
	solution:	An easy-to-understand but effective algorithm: Greedy
			Traverse the array, at each position update furthest position if current position is in the range of current furthest position.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int idx = 0;
        for(int i = 0; i < nums.size(); ++i)
            if(idx >= i)
                idx = max(idx, i + nums[i]);
        return idx >= nums.size() - 1;
    }
};
