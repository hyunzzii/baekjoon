#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* dirs) {
    int answer = 0;
    int xrr[11][11]={0,};
    int yrr[11][11]={0,};
    int x=5,y=5;
    for(int i=0;i<strlen(dirs);i++){
        if(dirs[i]=='U'){
            if(y+1>10){
                // answer-=1;
                continue;
            }
            yrr[x][++y]++;
        }
        if(dirs[i]=='D'){
            if(y-1<0){
                // answer-=1;
                continue;
            }
            yrr[x][y--]++;
        }
        if(dirs[i]=='R'){
            if(x+1>10){
                // answer-=1;
                continue;
            }
            xrr[++x][y]++;
        }
        if(dirs[i]=='L'){
            if(x-1<0){
                // answer-=1;
                continue;
            }
            xrr[x--][y]++;
        }
    }
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            // if(yrr[i][j]>1){
            // printf("%d %d : %d\n",i,j,xrr[i][j]);
            // }
            if(xrr[i][j]>0)answer++;
            if(yrr[i][j]>0)answer++;
        }
    }
    return answer;
}
