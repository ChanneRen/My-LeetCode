/*
	problem:	Group Anagrams
	difficulty:	medium
	description:	Given an array of strings, group anagrams together. 
			For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], return:
				[
				  ["ate", "eat","tea"],
				  ["nat","tan"],
				  ["bat"]
				]
	note:		All inputs will be in lower-case.
  	tags:		Hash-Table, String
	
	solution:	As the anagrams all have the same letters, so if we order them we will get the same string.
			So, the natural solution is to order each string and group them with a hash-table.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(auto str : strs)
        {
            string s = str;
            sort(s.begin(), s.end());
            hash[s].push_back(str);
        }
        vector<vector<string>> res;
        for(unordered_map<string, vector<string>>::iterator it = hash.begin(); it != hash.end(); ++it)
            res.push_back(it->second);
        return res;
    }
};

/*	
	But as the time complexity of order-algorithm is O(mlogm), so the complexity will be O(nmlogm).
	If there is a solution with complexity of O(nm), which means we don't order the string.
	Refer to others' solutions, I found them use an idea of encoding, which is ingenious.
*/


class Solution {
public:
    vector<int> prime{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<string>> hash;
        for(auto str : strs)
        {
            int key = 1;
            for(auto ch : str)
                key *= prime[ch - 'a'];
            hash[key].push_back(str);
        }
        vector<vector<string>> res;
        for(unordered_map<int, vector<string>>::iterator it = hash.begin(); it != hash.end(); ++it)
            res.push_back(it->second);
        return res;
    }
};
