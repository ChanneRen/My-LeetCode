
/*
	problem:	Letter Combinations of a Phone Number
	difficulty:	medium
	description:	Given a digit string, return all possible letter combinations that the number could represent.
    			A mapping of digit to letters is just like that on the telephone buttons.
	note:		Although the above answer is in lexicographical order, your answer could be in any order you want.
  	tags:		String, Backtracing
	
	solution:	It is simple using recursive algorithm: each time deal with a char of string in a loop.
*/

class Solution {
public:
    void recurMap(vector<string> map, vector<string> &res, string cur, string digits, int idx)
    {
        if(idx == digits.length())
            return;
        for(int i = 0; i < map[digits[idx] - '0'].length(); ++i)
        {
            cur[idx] = map[digits[idx] - '0'][i];
            if(idx == digits.length() - 1)
                res.push_back(cur);
            else
                recurMap(map, res, cur, digits, idx + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string cur = digits;
        recurMap(map, res, cur, digits, 0);
        return res;
    }
};


/*
	iterative solution
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const vector<string> map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if(digits.size() == 0)  return res;
        res.push_back("");
        for(int idx = 0; idx < digits.size(); ++idx)
        {
            int num = (int)(digits[idx] - '0'), cur = res.size();
            for(int j = 0; j < cur; ++j)
                for(int k = 0; k < map[num].length(); ++k)
                {
                    if(k == 0)
                        res[j].insert(res[j].end(), map[num][k]);
                    else
                    {
                        string s = res[j];
                        s[idx] = map[num][k];
                        res.push_back(s);
                    }
                }
        }
        return res;
    }
};
