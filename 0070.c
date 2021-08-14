#include <math.h>		/* pow */
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */

/*!
you are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

inline void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

int climbStairs(int n){
	int step[3] = {0,1,2};
	int ans = 0;
	if(n < 3)
	{
		return step[n];
	}
	else
	{
		for(int i = 3; i <= n; i++)
		{
			ans = step[2] + step[1];
			step[1] = ans;
			swap(&step[2], &step[1]);
			
		}
	}
	
	return ans;
	
}

int main()
{
	for(int i = 0; i < 30; i++)
	{
		printf("%d\r\n", climbStairs(i));
	}
	return 0;
}