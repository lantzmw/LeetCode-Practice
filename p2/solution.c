#include <stdlib.h>
#include <stdio.h>
/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
	int val;
	struct ListNode *next;
};

/*
Had to write my own exponenter as math.pow just wasn't working for me
*/
int myPow(int base, int exp)
{
	int ret = 1;
	int i;
	for(i = 0; i < exp; i++)
	{
		ret *= base;
	}
	
	return ret;
}

/*
get the actual number the listnode has
*/
int node2Int(struct ListNode* l)
{
    double decimalpos = 0.0;
    int number = 0;
    while(l != NULL)
    {
        number = (l->val * myPow(10,decimalpos)) + number;
        l = l->next;
        decimalpos += 1;
    }
    return number;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
  
    //convert nodes to ints
    int num1 = node2Int(l1);
    int num2 = node2Int(l2);
    int sum = num1 + num2;
        
    struct ListNode* retNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp = retNode;
    //divide up the sum to add to the listnode
    while(sum != 0)
    {
        temp->val = sum % 10;
        sum = sum / 10;
        		
        if(sum != 0)
        {
            temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp = temp->next;
        }
    }
	
	l1 = retNode;
    	
    return l1;
}


/*
run it!
*/
int main()
{
	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	
	//problem set 
	
	node1->val = 0;
	node2->val = 1;
	
	
	/*
	//problem set
	node1->val = 7;
	node1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	node1->next->val = 0;
	node1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	node1->next->next->val = 8;
	node2->val = 3;
	node2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	node2->next->val = 4;
	node2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	node2->next->next->val = 5;
	*/
	
	struct ListNode* ret = addTwoNumbers(node1,node2);
	
	while(ret != NULL)
	{
		printf("[%d]", ret->val);
		ret = ret->next;
	}
	printf("\n");
	
	free(node1);
	free(node2);
	free(ret);
}