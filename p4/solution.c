void mergesort(int*, int, int);
void merge(int*, int, int);
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
	
	//printf("combined\n"); printarray(combineArray, 0, length);
	
	//sort arrays
	mergesort(combineArray, 0, length-1);
	
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

/*
array - array to sort
beg - beg index of array
end - end index of array
*/
void mergesort(int* array, int beg, int end)
{
	if(beg >= end)	return;
	
	//find the middle
	int mid = (end+beg)/2;
	
	//printf("front at %d and %d\n", 0, mid); printarray(array, beg, mid);
	mergesort(array,beg,mid);
	//printf("back at %d and %d\n", mid+1, end); printarray(array, mid+1, end);
	mergesort(array,mid+1, end);
	
	merge(array, beg, end);
}

/*
do the work for the merge sort
front = front index
end = end of array index
*/
void merge(int* array, int front, int end)
{
	if(front >= end) return;
	
	int length = end - front + 1;
	int mid = (end+front) / 2;
	int i = 0;			//used as index into array
	int front_i = front;	//used as index to everything before mid
	int back_i = mid+1;		//used as index to everything after mid
	
	int* temp = (int*)malloc(sizeof(int)*(length));
	
	//printf("front: %d end: %d mid: %d\n", front, end, mid); printf("array:\n"); printarray(array,0,length-1); printf("temp\n"); printarray(temp,0,length-1);
	
	while((front_i <= mid) && (back_i <= end))
	{
		//check if front half is ordered
		if(array[front_i] < array[back_i])
		{
			temp[i] = array[front_i];
			front_i++;
			i++;
		}
		//otherwise back index needs to be in front
		else
		{
			temp[i] = array[back_i];
			back_i++;
			i++;
		}
		
		//printf("temp\n"); printarray(temp,0, length-1);
	}
	
	//'front array' may not be the same size as the 'back array'
	while(front_i <= mid)
	{
		temp[i] = array[front_i];
		front_i++;
		i++;
	}
	
	//'back array' may not be the same size as the 'front array'
	while(back_i <= end)
	{
		temp[i] = array[back_i];
		back_i++;
		i++;
	}
	
	//move everything from temp to final array
	for(i = front; i <= end; i++)
	{
		array[i] = temp[i-front];
	}
	
	//printf("final\n"); printarray(temp,0,length-1);
	
	free(temp);
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