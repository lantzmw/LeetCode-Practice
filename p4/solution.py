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