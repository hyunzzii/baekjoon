#include <cstdio>
int min(int a, int b){
    return a < b ? a : b;
}

int main(void){
    int N;
    int arr[1001] = {0,};
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&arr[i]);
        for(int j=1;j<=i/2;j++){
            arr[i] = min(arr[i], arr[j] + arr[i-j]);
        }
    }
    printf("%d",arr[N]);
}