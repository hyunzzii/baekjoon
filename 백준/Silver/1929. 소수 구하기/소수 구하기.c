#include<stdio.h>
#include<math.h>
int main() {int N,M,i = 0,s;scanf("%d %d", &M,&N);for (; M <= N; M++) {s = sqrt(M);
for (; s > 1; s--) {if (M % s == 0)break;}if (s == 1&&M!=1)printf("%d\n", M);}}