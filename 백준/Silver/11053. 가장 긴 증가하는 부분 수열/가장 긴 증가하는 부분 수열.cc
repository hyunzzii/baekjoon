#include <cstdio>
int N, arr[1000], dp[1000], idx=0;

void change(int s, int e, int target){
    int mid;
    while(s<e){
        mid = (s+e)/2;
        if(dp[mid] >= target){
            e = mid;
        }else{
            s = mid + 1;
        }
    }
    dp[e] = target;
}

int main(void){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    dp[0] = arr[0];
    for(int i=1;i<N;i++){
        if(dp[idx] < arr[i]){
            dp[++idx] = arr[i];
        }else{
            change(0,idx,arr[i]);
        }
    }
    printf("%d",idx+1);
}