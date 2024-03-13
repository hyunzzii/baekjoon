#include <iostream>

int main(void){
    int N,M;

    scanf("%d %d",&N,&M);
    
    unsigned int sum[100001];
    int start, end, tem;

    sum[0] = 0;
    for(int i=0; i<N; i++){
        scanf("%d",&tem);
        sum[i+1] = sum[i] + tem;
    }
    while(M--){
        scanf("%d %d",&start,&end);
        printf("%d\n",sum[end]-sum[start-1]);
    }
}