/*
	problem:	Search in Rotated Sorted Array
	difficulty:	medium
	description:	Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
    			(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
			You are given a target value to search. If found in the array return its index, otherwise return -1.
			You may assume no duplicate exists in the array.
  	tags:		Array, Binary Search
	
	solution:	At first, my solution is to resort the array in strictly ascending order, which is easy to realized for rotated array,
			and then I can use binary search. This method is practicable, but it seems to be a little low -_-||
			In fact, this problem can be resolved with the method of #Binary Search# directly as following steps:
			1.judge the position of middle number by comparing middle number with the first one;
			2.confirm a certain part which is strictly in ascending order according to the position of middle number;
			3.compare the target number with the end of the sorted part to update to-be-search part.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[left])
            {
                if(target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if(target <= nums[right] && target > nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            
        }
        return -1;
    }
};
