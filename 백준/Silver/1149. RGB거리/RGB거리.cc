#include <cstdio>
int min(int a, int b){
    return a < b ? a : b;
}

int main(void){
    int n, dp[1001][3] = {0,};
    scanf("%d",&n);
    int a,b,c;
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&a,&b,&c);
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + a;
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + b;
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + c;
    }
    printf("%d",min(min(dp[n][0], dp[n][1]),dp[n][2]));
}