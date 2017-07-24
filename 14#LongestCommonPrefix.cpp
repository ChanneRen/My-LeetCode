/*
	problem:	Longest Common Prefix
	difficulty:	easy
	description:	Write a function to find the longest common prefix string amongst an array of strings. 
  	tags:		String
	
	solution:	I don't have other solutions, just compare one by one.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)    return (string)"";
        string s = strs[0];
        for(int i = 1, j = 0; i < strs.size(); ++i)
        {
            for(j = 0; j < s.length() && j < strs[i].length(); ++j)
                if(s[j] != strs[i][j])
                    s.erase(s.begin() + j, s.end());
            if(j < s.length())
                s.erase(s.begin() + j, s.end());
        }
        return s;
    }
};
