#include <stdio.h>
int num(int N)
{
	int x,a,b,k;
	int count = 0;
	for (x = 100; x <= N; x++)
	{
		int tmp = x;
		while(x!=0)
		{
			a = x % 10;
			x = x / 10;
			b = x % 10;
			k = b - a;
			while (x != 0)
			{
				a = x % 10;
				x = x / 10;
				if (x == 0)
					break;
				b = x % 10;
				if ((x/10==0)&&((b - a) == k))
					count++;
			}
		}
		x = tmp;
	}
	return count;
}
int main(void)
{
	int N, m;
	scanf("%d", &N);
	if (N < 100)
		m = N;
	else
		m = 99 +num(N);
	printf("%d", m);
}