#include<stdio.h>
#include <math.h>

int result = 0;

void math(int s,int N){
    for (; s > 1; s--) {
        if (N % s == 0)break;
    }
	if(s==1 && N!=1)result++;
}
// 루트값 보다 작은 애들이 인수가 될테니...
int main() {
    int T,N,sum;
    scanf("%d", &T);
	for (; T > 0; T--){
        scanf("%d", &N);
        math(sqrt(N),N);
    }
    printf("%d", result);
}
