#include<stdio.h>
#include <math.h>
int main() {int T, x, y, i, result,sum;scanf("%d", &T);
	for (; T > 0; T--){result = 0;scanf("%d %d", &x, &y);sum = sqrt(y - x);
		if (sum*(sum+1) <= y - x){if (sum * (sum + 1) < y - x)result += 2 * sum + 1;else result += 2 * sum;}
		else{if (pow(sum, 2) < y - x)result += 1;result += 2 * sum - 1;}
		if (y - x == 3)result = 3;printf("%d\n", result);}}