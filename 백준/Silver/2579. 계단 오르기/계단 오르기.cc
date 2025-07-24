#include <cstdio>
int max(int a, int b){
    return a > b ? a : b;
}

int main(void){
    int n;
    int arr[301], dp[301] = {0,};
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    int a, b;
    for(int i=3;i<=n;i++){
        dp[i] = max(dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i]);
    }
    printf("%d",dp[n]);
}