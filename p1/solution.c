#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) 
{
    int *retArray;
    retArray = (int*)malloc(2*sizeof(int));
    
    int i, j;
    for(i = 0; i < numsSize; i++)
    {
        for(j = i+1; j < numsSize; j++)
        {
            int sum = nums[i] + nums[j];
            
            if(sum == target)
            {
                retArray[0] = i;
                retArray[1] = j;
            }
        }
    }
    return retArray;
}