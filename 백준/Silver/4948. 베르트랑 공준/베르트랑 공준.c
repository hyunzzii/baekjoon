#include<stdio.h>
#include<math.h>
int main() {int n,tmp, prime[22000],sum=0,i,k=0;prime[0] = 2;
for (tmp = 3; tmp <=246912; tmp++){for (i = 0; i <= k; i++) {if (tmp % prime[i] == 0)break;
else if (i == k){k++;prime[k] = tmp;}}}	for (;;sum=0) {scanf("%d", &n);if (n == 0)break;
for (i = 0;prime[i]<=2*n; i++){if (prime[i] > n && prime[i] <= 2 * n)sum++;}printf("%d\n", sum);}}