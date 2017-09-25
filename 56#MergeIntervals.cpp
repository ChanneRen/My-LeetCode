
/*
	problem:	Jump Game
	difficulty:	medium
	description:	Given a collection of intervals, merge all overlapping intervals.
			For example: Given [1,3],[2,6],[8,10],[15,18],
				return [1,6],[8,10],[15,18].
  	tags:		Array, Sort
	
	solution:	An easy-to-understand way is sort the intervals for start, then traverse and merge.
			I call the #STL algorithm:sort#, just cutomize the comparator.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(const Interval &a, const Interval &b)
    {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() < 2)    return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        int start = intervals[0].start, end = intervals[0].end;
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(end < intervals[i].start)
            {
                res.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
            else
                end = max(end, intervals[i].end);
        }
        res.push_back(Interval(start, end));
        return res;
    }
};
