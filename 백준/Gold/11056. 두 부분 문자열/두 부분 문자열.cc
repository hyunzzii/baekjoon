#include <cstdio>
#include <cstring>
int max(int a, int b){
    return a > b ? a : b;
}
int main(void){
    char a[1001], b[1001];
    int dp[1001][1001] = {0,};
    scanf("%s",a);
    scanf("%s",b);
    for(int i=0;i<strlen(a);i++){
        for(int j=0;j<strlen(b);j++){
            if(a[i] == b[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    printf("%d",strlen(a) + strlen(b) - dp[strlen(a)][strlen(b)]);
}