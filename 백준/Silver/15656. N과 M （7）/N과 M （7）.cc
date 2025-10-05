#include <cstdio>
#include <algorithm>
using namespace std;

int N,M;
int arr[8]={0,}, nrr[8]={0,};
void prt(int m){
    if(m == M){
        for(int i=0;i<M;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return ;
    }
    for(int i = 0; i<N; i++){
        arr[m] = nrr[i];
        prt(m+1);
    }
}

int main(void){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&nrr[i]);
    }
    sort(nrr, nrr+N);
    prt(0);
}