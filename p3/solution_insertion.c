#include <stdlib.h>
#include <stdio.h>
/*
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
*/
void insertsort(int*, int);
void printarray(int*,int, int);

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
	int length = nums1Size+nums2Size;
	//combining arrays
	int* combineArray = (int *)malloc(sizeof(int) * length);
	int i;
	for(i=0; i< nums1Size; i++)
	{
		combineArray[i] = nums1[i];
	}
	for(i=0; i<nums2Size; i++)
	{
		combineArray[i+nums1Size] = nums2[i];
	}
	
	printf("combined\n"); printarray(combineArray, 0, length-1);
	
	//sort arrays
	insertsort(combineArray, length);
	
	//check array
	printf("sorted\n"); printarray(combineArray, 0, length-1);
	
	int mid = length / 2;
	double median = 0;
	//find the mid point
	if(length % 2 == 0)
		median = (combineArray[mid-1] + combineArray[mid])/2.0;
	else
		median = combineArray[mid];
	
	return median;
}

void insertsort(int* array, int length)
{
	int temp;
	int element_i, compare_i;
	
	//go through each element of the array
	for(element_i = 1; element_i < length; element_i++)
	{
		temp = array[element_i];
		compare_i = element_i;
		while(compare_i > 0 && temp < array[compare_i-1])
		{
			array[compare_i] = array[compare_i-1];
			compare_i--;
		}
		array[compare_i] = temp;
	}
}

/*
ei - index, not length hence the <=
*/
void printarray(int* array, int si, int ei)
{
	int i;
	//check array
	for(i = si; i <= ei; i++)
		printf("[%d]", array[i]);
	printf("\n");
}

int main()
{
	int a1[] = {2,3,4};
	int a2[] = {1};
	
	double ret = findMedianSortedArrays(a1,3,a2,1);
	printf("%f\n" , ret);
}