#include <stdio.h>
#include <utility>
using namespace std;

long long int arr[5] = {2,1,1,1,2};       //반시계방향

long long int max(){
    long long int max = 0;
    int index;
    for(int i=0;i<5;i++){
        if(max<arr[i]){
            max=arr[i];
            index=i;
        }
    }
    arr[(index+1)%5] += arr[index];
    return max;
}

int main(void){
    long long int dp[101];

    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;

    for(int i=5;i<101;i++){
        dp[i] = max();
    }

    int T,n;
    scanf("%d",&T);

    while(T--){
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
}