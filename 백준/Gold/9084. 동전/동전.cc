#include <cstdio>
int main(void){
    int T, N, M, arr[20];
    scanf("%d",&T);
    while(T--){
        int dp[10001] = {0,};
        scanf("%d",&N);
        for(int i=0;i<N;i++) scanf("%d",&arr[i]);
        scanf("%d",&M);
        dp[0]=1;
        for(int i=0;i<N;i++){
            for(int j=1;j<=M;j++){
                if(j-arr[i] < 0) continue;
                dp[j] += dp[j-arr[i]];
            }
        }
        printf("%d\n",dp[M]);
    }
}