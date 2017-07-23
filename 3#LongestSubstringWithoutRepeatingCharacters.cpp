
/*
	problem:	Longest Substring Without Repeating Characters
	difficulty:	medium
	description:	Given a string, find the length of the longest substring without repeating characters. 
	examples:	Given "abcabcbb", the answer is "abc", which the length is 3.
			Given "bbbbb", the answer is "b", with the length of 1.
			Given "pwwkew", the answer is "wke", with the length of 3. 
			Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
  	tags:		String, Hash Table
	
	solution:	The key of this problem is to record the indices of prevoius characters and can visit directly to check if it has been appread.
			It is easy to think of Hash Table. But what's more, when a character is found, it means all characters in front of it don't need to discuss any more.
			So, we need a global variable to record the last repeating index.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int res = 0, start = -1;
        for(int i = 0; i < s.length(); ++i)
        {
            if(hash.find(s[i]) != hash.end() && hash[s[i]] > start)
                start = hash[s[i]];
            hash[s[i]] = i;
            res = max(res, i - start);
        }
        return res;
    }
};

/*
	optimize:	We need to check the pre-existence of current charecter and compare the index of repeating one with current one.
			And we need to traverse the hash-table every time. As we just need the index of the character, and consider the number of chars,
			we just need an array like a dictionary.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int res = 0, start = -1;
        for(int i = 0; i < s.length(); ++i)
        {
            if(hash[s[i]] > start)
                start = hash[s[i]];
            hash[s[i]] = i;
            res = max(res, i - start);
        }
        return res;
    }
};
