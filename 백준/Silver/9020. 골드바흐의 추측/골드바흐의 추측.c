#include<stdio.h>
int main() {int T, n, tmp, a = 0, b = 0, prime[10000],i, k = 0;prime[0] = 2;
for (tmp = 3; tmp <= 10000; tmp++){for (i = 0; i <= k; i++) {if (tmp % prime[i] == 0)break;
else if (i == k){k++;prime[k] = tmp;}}}scanf("%d", &T);
for (; T > 0; T--,a=0,b=0) {scanf("%d", &n);tmp = n / 2;for (i = 0;; i++){if (tmp <= prime[i])break;}
if (prime[i] * 2 == n) {printf("%d %d\n", prime[i], prime[i]); continue;}
while (1) {if (prime[i - a] + prime[i + b] == n) {
printf("%d %d\n", prime[i - a], prime[i + b]); break;}
if (prime[i - a] + prime[i + b] > n)a++;
if (prime[i - a] + prime[i + b] < n)	b++;}}}