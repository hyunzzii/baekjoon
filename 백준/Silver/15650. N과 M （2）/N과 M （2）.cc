#include <stdio.h>
using namespace std;

int n,m;
int arr[9];

void func(int num, int index){
    arr[index] = num;

    if(index == m-1){
        for(int i=0;i<=index;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=num+1; i<n+1; i++){
        func(i,index+1);
    }
}

int main(void){
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){
        func(i, 0);
    }    
}