#include <cstdio>

int main(void){
    int n;
    long long sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum += (n/i) * i;
    }
    printf("%lld",sum);
}