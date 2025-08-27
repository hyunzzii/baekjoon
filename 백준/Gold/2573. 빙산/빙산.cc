#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr[302][302], brr[302][302] = {0,};

int dfs(int x, int y){
    int visited[302][302]={0,}, sum=0;
    stack<pair<int,int>> s;
    s.push({x,y});
    visited[x][y] = 1;
    while(!s.empty()){
        x = s.top().first;
        y = s.top().second;
        sum++;
        s.pop();
        for(int i=0;i<4;i++){
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(arr[tx][ty] && !visited[tx][ty]){
                s.push({tx,ty});
                visited[tx][ty] = 1;
            }
        }
    }
    return sum;
}
int main(void){
    int N,M;
    int ans=0,num=0,tx,ty,ux,uy;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(!arr[i][j]) continue;
            num++;
            for(int k=0;k<4;k++){
                tx = i+dx[k];
                ty = j+dy[k];
                if(!arr[tx][ty]) brr[i][j]++;
            }
        }
    }
    int dx[2] = {1,0};
    int dy[2] = {0,1};
    do{
        ans++;
        ux=0,uy=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(!arr[i][j]) continue;
                arr[i][j] -= brr[i][j];
                if(arr[i][j] <= 0){
                    num--;
                    arr[i][j] = 0;
                    brr[i][j] = 0;
                    for(int k=0;k<2;k++){
                        tx = i+dx[k];
                        ty = j+dy[k];
                        if(arr[tx][ty]){
                            arr[tx][ty]++;
                            brr[tx][ty]++;
                        }
                    }
                    for(int k=0;k<2;k++){
                        tx = i-dx[k];
                        ty = j-dy[k];
                        if(arr[tx][ty]){
                            brr[tx][ty]++;
                        }
                    }
                }else{
                    ux=i, uy=j;
                }
            }
        }
    }while(ux && (dfs(ux,uy)==num));
    if(!ux) printf("0");
    else printf("%d",ans);
}