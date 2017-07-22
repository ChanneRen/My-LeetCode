
/*
	problem:	Climbing Stairs
	difficulty:	easy
	description:	You are climbing a stair case. It takes n steps to reach to the top.
    			Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
	note:		Given n will be a positive integer.
  	tags:		Dynamic Programming
	
	solution:	Consider xth step of the stair (x <= n), as I can cimb 1 or 2 step each time, so if we want to get step x, we must climb from 
			(x - 1)th or (x - 2)th step. So f(x) = f(x - 1) + f(x - 2) where f(x) is the number of ways to get to xth step.
			Of course this is the formula of Fibonacci sequence.
*/

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        for(int i = 2; i <= n; ++i)
        {
            int temp = b;
            b += a;
            a = temp;
        }
        return b;
    }
};
