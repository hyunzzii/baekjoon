#include <stdio.h>
using namespace std;

int main(void){
    long long int dp[101] = {0,1,1,1,2,2,3};

    for(int i=7,num=0; i<101; i++){
        dp[i] = dp[i-1]+dp[i-5];
    }

    int T,n;
    scanf("%d",&T);

    while(T--){
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
}