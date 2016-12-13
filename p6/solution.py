class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        
        #set up the arrays
        zz = []
        for i in range(0,numRows):
        	zz.append("")
        	
        print s	
        	
        #go through s and place char appropriately
        increment = 1
        rindex = 0
        for c in s:
        
        	#print("inc: %d rindex: %d c: %c" % (increment, rindex, c))
          	zz[rindex] += c
          	
          	#if rindex is at the end of the array, change increment
          	if rindex == (numRows-1):
          		increment = numRows - 1
          	#if rindex has circled back to 0, go back to 1
          	if rindex == 0:
          		increment = 1
          	
          	rindex = (rindex + increment) % numRows  	
               	
        	#print(zz)
        	
            
        return "".join(zz)