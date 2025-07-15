#include <cstdio>
int main(void){
    int arr[11];
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i=4;i<11;i++){
        arr[i] = arr[i-3] + arr[i-2] + arr[i-1];
    }

    int T, tmp;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&tmp);
        printf("%d\n",arr[tmp]);
    }
}