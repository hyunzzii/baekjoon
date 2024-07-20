#include<stdio.h>
#include <algorithm>
using namespace std;

int main(void){
    int T;
    scanf("%d",&T);

    while(T-- > 0){
        int N,M;
        scanf("%d %d",&N,&M);

        int origin[N], prio[N];
        for(int i=0; i<N; i++){
            scanf("%d",&origin[i]);
            prio[i] = -origin[i];
        }
        sort(prio,prio+N);
        int o=0, p=0, count=0;
        while(true){
            while(prio[p]!=-origin[o]){
                o = (o+1)%N;
            }
            origin[o] = 0;
            p++;

            count++;
            if(o==M)break;
        }
        printf("%d\n",count);
    }
}