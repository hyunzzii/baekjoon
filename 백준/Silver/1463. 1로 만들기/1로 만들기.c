#include <stdio.h>
#define min(a,b) a < b ? a : b
int main()
{
	int X, D[1000001];
	scanf("%d",&X);
	D[0] = 0; D[1] = 0;
	for (int i = 2; i<=X;i++) {
		D[i] = D[i - 1] + 1;
       if (i % 3 == 0 && i % 2 == 0) {
			D[i] = min(D[i], D[i / 3] + 1);
			D[i] = min(D[i], D[i / 2] + 1);
       }
		else if (i % 2 == 0)
			D[i] = min(D[i], D[i / 2] + 1);
		else if (i % 3 == 0)
			D[i] = min(D[i], D[i / 3] + 1);
	}
	printf("%d", D[X]);
	return 0;
}