#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(void){
    int n,m;
    int maze[102][102] = {0,};
    queue<pair<int,int>> q;
    
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&maze[i][j]);
        }
    }

    q.push(make_pair(1,1));
    maze[1][1]=2;
    while(true){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x==n && y==m){
            break;
        }
        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(maze[newx][newy]==1){
                q.push(make_pair(newx,newy));
                maze[newx][newy]=maze[x][y]+1;
            }
        }
    }
    printf("%d",maze[n][m]-1);
} 