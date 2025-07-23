#include <cstdio>
int main(void){
    int n, dp[31]={0,};
    scanf("%d",&n);
    dp[2] = 3;
    for(int i=4;i<=n;i+=2){
        for(int j=2;j<i;j+=2){
            dp[i] += 2*dp[i-j];
        }
        dp[i] += dp[i-2] + 2;
    }
    printf("%d",dp[n]);
}