#include <cstdio>
int max(int a, int b){
    return a > b ? a : b;
}
int main(void){
    int N, ans=0;
    int dp[10001] = {0,};
    int arr[10001] = {0,};
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&arr[i]);
    }
    dp[1] = arr[1];
    dp[2] = dp[1] + arr[2];
    ans = dp[2];
    for(int i=3;i<=N;i++){
        dp[i] = max(max(dp[i-3]+arr[i-1], dp[i-2]) + arr[i], dp[i-1]);
        if(ans < dp[i]) ans = dp[i];
    }
    printf("%d",ans);
}