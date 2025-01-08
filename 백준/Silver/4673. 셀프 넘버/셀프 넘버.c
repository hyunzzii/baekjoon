#include <stdio.h>
#define SIZE 10000
int D (int x)
{
	int sum=x;
	while (x!=0)
	{
		sum += x % 10;
		x = x / 10;
	}
	return sum;
}

int main(void)
{
	int x, sum, i;
	for (x = 1; x <= SIZE; x++)
	{
		for(i = 1; i <= x ;i++)
		{	
			sum = D(i);
			if (sum == x)
				break;
		}
		if ((i-1) == x)
			printf("%d\n",x);
	}
}