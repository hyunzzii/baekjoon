#include <stdio.h>
using namespace std;

int n,m;
int arr[9];

void func(int num, int index){
    if(index == m){
        for(int i=0;i<index;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }

    for(int i=num+1; i<n+1; i++){
        arr[index] = i;
        func(i,index+1);
    }
}

int main(void){
    scanf("%d %d",&n,&m);
    func(0,0);
}