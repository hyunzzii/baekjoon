#include <stdio.h>

int main(void) {
	int n, tem, p = 0, q = 0, max = -1001;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tem);
		if (tem > max)max = tem;
		q = q + tem < 0 ? 0 : q + tem;
		if (q > p)p = q;
	}
	printf("%d\n", p == 0 ? max : p);
}