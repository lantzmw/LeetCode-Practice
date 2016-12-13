#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

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

int reverse(int x) 
{
	int ret = 0;
	int decimalpos = 0;
	int sign = 1;
	int remainder = 0;
	
	if(x < 0)
		sign = -1;

	while(x != 0)
	{
		remainder = x % 10;
		x = x / 10;
				
		ret = (ret * 10) + remainder;
		decimalpos++;
		if(ret >= 220000000 && x != 0)
			return 0;
			
	}
	//make sure it doesn't overflow or underflow: max_int typically is 2147483647
	if((sign > 0 && ret < 0) || (sign < 0 && ret > 0))
		return 0;

	return (ret);
}

void printRet(int num)
{
	printf("Number: %10d Reverse: %10d\n" , num, reverse(num));
}


int main()
{
	int a[] = {0, 1, 10, 15, 100, 99, 999, -9, -25, -7985241, -0, -1, 0, 0, 1534236469, 1000000003};
		
	int i;
	for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
		printRet(a[i]);
}
