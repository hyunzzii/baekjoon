#include <stdio.h>
using namespace std;

int main(void){
    long long int arr[5] = {2,1,1,1,2};
    long long int dp[101];

    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;

    for(int i=5,num=0; i<101; i++){
        dp[i] = arr[num];
        arr[(num+1)%5] += arr[num];
        num = (num+1)%5;
    }

    int T,n;
    scanf("%d",&T);

    while(T--){
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
}