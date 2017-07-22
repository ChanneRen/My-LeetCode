/*
	problem:	Two Sum
	difficulty:	easy
	description:	Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    			You may assume that each input would have exactly one solution, and you may not use the same element twice.
  	tags:		Array, Hash Table
	
	solution:	For this question, we need to return indices, so we could not use two pointers to search after sorting array. 
			As we have and only have exact two numbers added up to the target number. So,
			Just to traverse the array, for each number, check if it is one of the two, we need to check numbers that have been traversed.
			Then, how to check if one number has appeared as fast as possible? Of course Hash Table.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(hash.find(target - nums[i]) != hash.end())
            {
                res.push_back(hash[target - nums[i]]);
                res.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return res;
    }
};
