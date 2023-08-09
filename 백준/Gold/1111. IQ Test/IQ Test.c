#include <stdio.h>
int main()
{
	int N, i,arr[50],a=0,b=0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	if (N < 3) {
		if (N == 2 && arr[0] == arr[1]) { printf("%d", arr[0]); return 0; }
		else { printf("A"); return 0; }
		}
	if (arr[1] - arr[0] == 0) { if (arr[2] - arr[1] == 0) { a = 1; b = 0; } else { printf("B"); return 0; } }
	else {
		a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
		b = arr[1] - (arr[0] * a);
	}
	for (i = 0; i < N-1; i++)
	{
		if (arr[i] * a + b != arr[i + 1]) { printf("B"); return 0; }
	}
	printf("%d", arr[N - 1] * a + b);
}