/*
	problem:	Valid Parentheses
	difficulty:	easy
	description:	Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    			The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
  	tags:		Strign, Stack
	
	solution:	It is an easy but classic problem working with stack.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(auto ch : s)
        {
            if(ch == '(' || ch == '[' || ch == '{')
                S.push(ch);
            else
            {
                if(S.empty())   return false;
                char topchar = S.top();
                S.pop();
                if(topchar == '(' && ch != ')') return false;
                if(topchar == '[' && ch != ']') return false;
                if(topchar == '{' && ch != '}') return false;
            }
        }
        return S.empty();
    }
};
