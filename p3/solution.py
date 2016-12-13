"""
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
"""

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        fulllist = nums1 + nums2
        
        fulllist.sort()

        mid = int(len(fulllist) / 2)

        #if list is even length
        if (len(fulllist) % 2) == 0:
            n1 = fulllist[mid-1]
            n2 = fulllist[mid]
            median = (n1 + n2) / 2.0
        else:
            median = fulllist[mid]
        
        return median