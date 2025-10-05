#include <cstdio>
#include <algorithm>
using namespace std;

int N,M;
int arr[8] = {0,}, nrr[8] = {10001,10001,10001,10001,10001,10001,10001,10001};
bool visited[8];
void prt(int n, int m){
    if(m == M){
        for(int i=0;i<M;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return ;
    }
    for(int i = 0; i<N; i++){
        if(!visited[i]){
            arr[m] = nrr[i];
            visited[i] = true;
            prt(n+1, m+1);
            visited[i] = false;
        }
    }
}

int main(void){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&nrr[i]);
    }
    sort(nrr, nrr+8);
    prt(0,0);
}