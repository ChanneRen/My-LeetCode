
/*
	problem:	Next Permutation
	difficulty:	medium
	description:	Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. 
			If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
			The replacement must be in-place, do not allocate extra memory.
			Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
				1,2,3 → 1,3,2
				3,2,1 → 1,2,3
				1,1,5 → 1,5,1
  	tags:		Array
	
	solution:	for an array with n numbers, find its next-permutation if it exists:
			1. find the max k which satisfy array[k] < array[k + 1];
			2. find the j which satisfy j > k and array[j] is the minimum number which is larger than array[k]. It must exist.
			3. swap array[k] and array[j];
			4. reverse the order of sequence array[k + 1] to array[n]
			if the array is in descending order, then it won't have next permutation, or you can say the ascending order is.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), idx = n - 2;
        for(; idx >= 0; --idx)
        {
            if(nums[idx] >= nums[idx + 1])  continue;
            int j = n - 1;
            while(nums[j] <= nums[idx]) --j;
            swap(nums[j], nums[idx]);
            int l = idx + 1, r = n - 1;
            while(l < r)
                swap(nums[l++], nums[r--]);
            break;
        }
        if(idx == -1)
        {
            int l = idx + 1, r = n - 1;
            while(l < r)
                swap(nums[l++], nums[r--]);
        }
    }
};
