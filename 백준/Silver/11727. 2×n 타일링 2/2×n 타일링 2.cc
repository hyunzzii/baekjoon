#include <cstdio>
int n;
int arr[10001] = {0,};

int main(void){
    scanf("%d",&n);
    arr[1] = 1;
    arr[2] = 3;
    for(int i=3;i<=n;i++){
        arr[i] = (arr[i-1] + arr[i-2]*2) % 10007;
    }
    printf("%d",arr[n]);
}