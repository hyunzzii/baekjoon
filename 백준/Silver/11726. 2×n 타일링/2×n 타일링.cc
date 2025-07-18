#include <cstdio>
int main(void){
    int n,arr[1001]={0,};
    scanf("%d",&n);
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3;i<=n;i++){
        arr[i] = (arr[i-2] + arr[i-1]) % 10007;
    }
    printf("%d",arr[n]);
}