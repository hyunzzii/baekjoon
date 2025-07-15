#include <cstdio>
int main(void){
    int N, T, P;
    int dp[21] = {0,};
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d %d",&T,&P);
        if(dp[i-1] + P > dp[i+T-1]){
            dp[i+T-1] = dp[i-1] + P;
        }
        if(dp[i] < dp[i-1]){
            dp[i] = dp[i-1];
        }
    }
    printf("%d",dp[N]);
}