#include <cstdio>
#include <climits>
using namespace std;
#define min(a,b) (a < b) ? a : b

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(void){
    int N,r,c,s[501];
    int board[501][501] = {0,};
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d %d",&r,&c);
        s[i-1] = r;
        if(i == N) s[i] = c;
    }
    for(int i=1;i<N;i++){
        for(int r=1;r+i<=N;r++){
            c = r+i;
            if(!board[r][c]) board[r][c] = INT_MAX;
            for(int k=0;k<i;k++){
                board[r][c] = min(board[r][c], board[r][c-k-1] + board[c-k][c] + s[r-1]*s[c]*s[c-k-1]);
            }
        }
    }
    printf("%d",board[1][N]);
}