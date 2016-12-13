"""
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
"""

# Definition for singly-linked list.
#class ListNode(object):
#	def __init__(self, x):
#		self.val = x
#		self.next = None

class Solution(object):
	def addTwoNumbers(self, l1, l2):
		"""
		:type l1: ListNode
		:type l2: ListNode
		:rtype: ListNode
		"""
		
		#convert list to an integer
		sum1 = self.list2Integer(l1)
		sum2 = self.list2Integer(l2)
		
		#add the two numbers
		rsum = sum1 + sum2
		
		#convert back to a linked list
		rList = self.integer2List(rsum)
		
		return rList
		
	def list2Integer(self, l):
		"""
		Take a linked list as defined above and convert it to an integer
		:type l: ListNode
		"""
		#add all values to a list. this will be used to determine the number of digits in a number
		sumList = []
		while l != None:
			sumList.append(int(l.val))
			l = l.next
		
		sumList.reverse()
		
		#multiplier is used to shift each digit to its correct place
		multiplier = 10 ** ((len(sumList))-1)		#-1 because we only care about the zeros in the multiplier
		
		#create the integer
		sum = 0
		for num in sumList:
			sum += num * multiplier				#move each digit to its correct spot
			multiplier = multiplier / 10		#decrease multiplier
			
		return int(sum)
		
	def integer2List(self, i):
		"""
		Take an intege and convert it to a linked list as defined above
		:type i: integer
		"""
		rList = ListNode(0)		#this will point ot the beginning
		rl = rList				#use this as a working list
		
		while True:				#emulating a do while loop
			rl.val = i % 10		#single out a digit
			i = int(i / 10)		#shift number over
			
			#if there are still numbers to parse
			if i != 0:
				rl.next = ListNode(0)
				rl = rl.next
			else:				#otherwise stop
				break
		
		return rList