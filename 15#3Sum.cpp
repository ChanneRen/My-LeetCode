/*
	problem:	Two Sum
	difficulty:	medium
	description:	Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
			Find all unique triplets in the array which gives the sum of zero.
	note:		The solution set must not contain duplicate triplets.
  	tags:		Array, Two Pointers
	
	solution:	Consider a + b + c = 0, it equals a + b = -c. So:
			For each number x, we need to check if there are two numbers a, b such that a + b = -x. So we change this problem to two sum.
			For two sum problem, which means find two numbers added up to a target number, we could sort the array and use two pointers.
			More hints:
			1. problem requests to find all unique triplets, which means there may exist more than one solutions and there may be duplicates in the array;
			2. to find all triplets, we must traverse all numbers for each time; and for unique ones we need skip all duplicates;
			3. as the sum is zero and we have sorted the array, so if the first number is larger than zero, then there couln't be solution.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 3) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2 && nums[i] <= 0;)
        {
            int twoSum = -nums[i];
            int l = i + 1, r = n - 1;
            while(l < r)
            {
                int sum = nums[l] + nums[r];
                if(sum < twoSum)
                    l++;
                else if(sum > twoSum)
                    r--;
                else
                {
                    res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1]) l++;
                    while(l < r && nums[r] == nums[r + 1]) r--;
                }
            }
            while(++i < n && nums[i] == nums[i - 1]);
        }
        return res;
    }
};
