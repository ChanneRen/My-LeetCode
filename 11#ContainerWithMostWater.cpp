/*
	problem:	Container With Most Water
	difficulty:	medium
	description:	Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
			n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
			Find two lines, which together with x-axis forms a container, such that the container contains the most water.
	note:		You may not slant the container and n is at least 2.
  	tags:		Array, Two Pointers
	
	solution:	As the volumn of water equals to height multiplied by width. To get most water, we would like to make width and height larger.
			First, from the start point to the end point, we get the largest width.
			Then, we need to reduce the width gradually, as the width reducing, the height must go higher, or the water cannot increase.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, l = 0, r = height.size() - 1;
        while(l < r)
        {
            if(height[l] < height[r])
            {
                res = max(res, (r - l) * height[l]);
                l++;
            }
            else
            {
                res = max(res, (r - l) * height[r]);
                r--;
            }
        }
        return res;
    }
};

/* while changing width, we can check the new height to skip some point whose height is lower than current height */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, l = 0, r = height.size() - 1;
        while(l < r)
        {
            int h = min(height[l], height[r]);
            res = max(res, (r - l) * h);
            while(height[l] <= h && l < r)   ++l;
            while(height[r] <= h && l < r)   --r;
        }
        return res;
    }
};
