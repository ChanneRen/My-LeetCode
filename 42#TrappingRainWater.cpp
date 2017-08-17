/*
	problem:	Trapping Rain Water
	difficulty:	hard
	description:	Given n non-negative integers representing an elevation map where the width of each bar is 1, 
			compute how much water it is able to trap after raining. 
			For example, Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
  	tags:		Array, Two Pointers, stack
	
	solution:	This problem is similar with the problem #11 Container With Most Water#. The difference is we are not seeking two lines 
			to get the largest container, instead each pair of line with different height can be a vector.
			The same idea: use two pointers but for each line with lower height, its capacity is determined not only by its higher pair 
				but also the highest line before it.
			Thus we need not only two pointers to tranverse but also two pointers to record the highest height for both left and right.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxL = 0, maxR = 0, res = 0;
        while(left <= right)
        {
            if(height[left] < height[right])
            {
                if(height[left] < maxL)
                    res += min(maxL, height[right]) - height[left];
                maxL = max(maxL, height[left]);
                ++left;
            }
            else
            {
                if(height[right] < maxR)
                    res += min(height[left], maxR) - height[right];
                maxR = max(maxR, height[right]);
                --right;
            }
        }
        return res;
    }
};
