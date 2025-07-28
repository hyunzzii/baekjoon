#include <cstdio>
int main(void){
    int T, N, M, arr[20];
    scanf("%d",&T);
    while(T--){
        int dp[10001][20] = {0,}, sum = 0;
        scanf("%d",&N);
        for(int i=0;i<N;i++) scanf("%d",&arr[i]);
        scanf("%d",&M);
        for(int i=1;i<=M;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<=j;k++){
                    if(i-arr[j] < 0) break;
                    if(i-arr[j] == 0) dp[i][j] = 1;
                    dp[i][j] += dp[i-arr[j]][k];
                }
            }
        }
        for(int i=0;i<N;i++) sum += dp[M][i];
        printf("%d\n",sum);
    }
}