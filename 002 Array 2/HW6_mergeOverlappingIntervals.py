# Merge Overlapping Intervals
# Problem Description

# Given a collection of intervals, merge all overlapping intervals.


# Problem Constraints
# 1 <= Total number of intervals <= 100000.


# Input Format
# First argument is a list of intervals.


# Output Format
# Return the sorted list of intervals after merging all the overlapping intervals.


# Example Input
# Input 1:

# [1,3],[2,6],[8,10],[15,18]


# Example Output
# Output 1:

# [1,6],[8,10],[15,18]


# Example Explanation
# Explanation 1:

# Merge intervals [1,3] and [2,6] -> [1,6].
# so, the required answer after merging is [1,6],[8,10],[15,18].
# No more overlapping intervals present.

# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    # @param intervals, a list of Intervals
    # @return a list of Interval
    def merge(self, intervals):

        intervals.sort(key=lambda x: x.start)

        out = []
        out.append(intervals[0])
        index = 0

        for i in range(1, len(intervals)):
            if intervals[i].start <= out[index].end:
                out[index].end = max(out[index].end, intervals[i].end)

            elif intervals[i].start > out[index].end:
                out.append(intervals[i])
                index = index + 1

        return out
