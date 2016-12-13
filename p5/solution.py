class Solution(object):
	def longestPalindrome(self, s):
		"""
		:type s: str
		:rtype: str
		"""
		longest = ''
		adjuster = 0
		#go in reverse order through a string
		for ss in range(len(s),0,-1):
			
			substring = s[0:ss]
			palindrome = self.findPalindrome(substring)
			print("ss: %d longest %s palindrome %s" % (ss, longest, palindrome))
			#if there hasn't been a longest before, than this is automatically the longest
			if longest == '':
				longest = palindrome
				#if the longest is the same as the original string passed in, then no need to look further
				if longest == s:
					break
			#otherwise check if the found palindrome is the longest		
			elif len(palindrome) >= len(longest):
				longest = palindrome
		
		return longest	
		
	
	def findPalindrome(self, s):
		slen = len(s)
		mid = slen / 2
		longest = ''
		print("Testing %s" % s)

		#base case, nothing to check
		if slen <= 1: 
			return s

		#is front a palindrome
		if self.checkPalindrome(s):
			#check if its the longest
			if len(s) > len(longest):
				longest = s
		#if top string is not a palindrome, 
		else:
			#cut in half and see if that is the longest palindrome
			print("finding in front half")
			front = self.findPalindrome(s[:mid])
			
			back = ''
			#and test the back half as well
			print("finding in back half")
			if(slen % 2 == 0):
				back = self.findPalindrome(s[mid:])
			else: 
				back = self.findPalindrome(s[mid+1:])
			
			#determine which is the longer palindrome
			
			print("Front %s vs back %s" % (front, back))
			if(len(front) > len(back)):
				longest = front
			else:
				longest = back
			
			print("longest is %s" % longest)	

		return longest

	def checkPalindrome(self, s):
		"""
		check if the first part of a string is == to the back
		"""
		l = len(s)
		mid = l / 2
		front = ''
		back = ''
		ret = False
		
		front = s[:mid]

		#if even
		if(l%2 == 0):
			back = s[mid:]
		else:
			back = s[mid+1:]

		#check if the strings are the same
		if front == back[::-1]:
			ret = True

		return ret
	
sol = Solution()

"""
string = "ababa"
longest = sol.longestPalindrome(string)
print("Longest Palindrome of %s is %s" % (string,longest))

string = "abaaba"
longest = sol.longestPalindrome(string)
print("Longest Palindrome of %s is %s" % (string,longest))

string = "abgvba"
longest = sol.longestPalindrome(string)
print("Longest Palindrome of %s is %s" % (string,longest))

string = "abaqwerty"
longest = sol.longestPalindrome(string)
print("Longest Palindrome of %s is %s" % (string,longest))

string = "babad"
longest = sol.longestPalindrome(string)
print("Longest Palindrome of %s is %s" % (string,longest))
"""
string = "cbbd"
longest = sol.longestPalindrome(string)
print("Longest Palindrome of %s is %s" % (string,longest))