#include <cstdio>
int main(void){
    int n,tem,i=0,sum=0,result=0;
    scanf("%d",&n);
    int arr[1001] = {0,};

    for(i=0;i<n;i++){
        scanf("%d",&tem);
        arr[tem]++;
    }
    i=0;
    while(n>0){
        while(arr[i]--){
            result += sum + i;
            sum += i;
            n--;
        }
        i++;
    }
    printf("%d",result);
}