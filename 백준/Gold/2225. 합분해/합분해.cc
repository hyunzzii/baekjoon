#include <cstdio>
using namespace std;

int main(void){
    int n,k;
    scanf("%d %d",&n,&k);

    int dp[201][201] = {0,};

    for(int i=1;i<=n;i++){
        dp[i][1] = 1;
    }
    for(int j=1;j<=k;j++){
        dp[0][j] = 1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=2;j<=k;j++){
            dp[i][j] =(dp[i][j-1] + dp[i-1][j]) % 1000000000;
        }
    }
    printf("%d",dp[n][k]);
} 