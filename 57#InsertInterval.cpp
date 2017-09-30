/*
	problem:	Insert Interval
	difficulty:	medium
	description:	Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
			You may assume that the intervals were initially sorted according to their start times.
			For example: Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
				Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
				This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
  	tags:		Array, Sort
	
	solution:	This problem is based on #Problem 56 Merge Intervals#
			As the intervals are initially sorted according to their start times, we can find position to inert new interval easily.
			From the position found for inserting traversing to check overlaps:
				if overlap exists, update new interval to be the largest interval.
			Erase intervals which are overlaps and insert new interval to the position found before.
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int idx = 0, n = intervals.size();
        while(idx < n && newInterval.start > intervals[idx].end) idx++;
        int pos = idx;
        while(idx < n && newInterval.end >= intervals[idx].start)
        {
            newInterval.start = min(intervals[idx].start, newInterval.start);
            newInterval.end = max(intervals[idx].end, newInterval.end);
            idx++;
        }
        if(pos < n && idx > pos)
            intervals.erase(intervals.begin() + pos, intervals.begin() + idx);
        intervals.insert(intervals.begin() + pos, newInterval);
        return intervals;
    }
};
