#include <math.h>		/* pow */
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
/*
	Given a 32-bit signed integer, reverse digits of an integer.
*/

int reverse(int x){
    int ans = 0;
    
    while (x != 0)
    {
        int pop = x % 10;
        x /= 10;
        if (ans > INT_MAX/10 || (ans == INT_MAX / 10 && pop > 7)) return 0;
        if (ans < INT_MIN/10 || (ans == INT_MIN / 10 && pop < -8)) return 0;
        ans = ans * 10 + pop;
    }
    
    return ans;
}


int main(void)
{
	printf("%d\r\n", reverse(123));
	printf("%d\r\n", reverse(-123));
	printf("%d\r\n", reverse(1234567899));
	return 0;
}