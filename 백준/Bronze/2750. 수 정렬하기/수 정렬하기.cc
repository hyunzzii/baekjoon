#include <stdio.h>
using namespace std;

int main(void){
    int N,tem,num=0;
    int arr[2001] = {0,};
    
    scanf("%d",&N);
    while(N--){
        scanf("%d",&tem);
        arr[1000 + tem] = 1;
    }
    for(int i = 0; i < 2001; i++){
        if(arr[i]){
            printf("%d\n",i-1000);
            if(++num == N) return 0;
        }
    }
}