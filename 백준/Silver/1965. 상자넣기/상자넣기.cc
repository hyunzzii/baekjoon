#include <cstdio>

int N, arr[1001], dp[1001], len=0;
void change(int s, int e, int target){
    while(s<e){
        int mid = (s+e)/2;
        if(dp[mid] < target) s = mid+1;
        else e = mid;
    }
    dp[e] =  target;
}

int main(void){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&arr[i]);
    dp[0] = arr[0];
    for(int i=1;i<N;i++){
        if(dp[len] < arr[i]) dp[++len] = arr[i];
        else change(0,len,arr[i]);
    }
    printf("%d",len+1);
}