#include <stdio.h>
int main(void) {
	int n, max = 0;
	scanf("%d", &n);
	int* a = malloc(sizeof(int) * n);
	int* d = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		d[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++)
			if (a[j] < a[i] && d[i] <= d[j])
				d[i] = d[j] + 1;
	}
	for (int i = 0; i < n; i++)
		if (d[i] > max)
			max = d[i];
	printf("%d", max);
}