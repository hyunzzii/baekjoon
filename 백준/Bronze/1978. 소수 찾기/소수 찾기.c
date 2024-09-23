#include<stdio.h>
#include <math.h>
void math(int s,int N,int*result)
{for (; s > 1; s--) {if (N % s == 0 || s == 1)break;}
	if(s==1&&N!=1)	*result += 1;}
int main() {int T,N,sum,result=0;scanf("%d", &T);
	for (; T > 0; T--){scanf("%d", &N);math(sqrt(N),N,&result);}printf("%d", result);}