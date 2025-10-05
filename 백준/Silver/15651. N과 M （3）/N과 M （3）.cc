#include <cstdio>

int N,M;
char str[15] = {0,};
void prt(int m){
    if(m == M){
        printf("%s\n",str);
        return ;
    }
    for(int i = 1; i<=N; i++){
        str[m*2] = i + '0';
        str[m*2+1] = ' ';
        prt(m+1);
    }
}

int main(void){
    scanf("%d %d",&N,&M);
    prt(0);
}