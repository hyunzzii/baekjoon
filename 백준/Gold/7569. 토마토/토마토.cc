#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct{
    int z;
    int x;
    int y;
} node;
queue<node> q[2];
vector<vector<vector<int>>> graph;
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N, H;
    cin >> M >> N >> H;
    graph = vector<vector<vector<int>>> (H+2,vector<vector<int>>(N+2, vector<int>(M+2,0)));

    int tx,ty,tz,remain=0, cur=0, ans=0;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=M;k++){
                cin >> graph[i][j][k];
                graph[i][j][k]++;
                if(graph[i][j][k]==1) remain++;
                else if(graph[i][j][k]==2) q[cur].push({i,j,k});
            }
        }
    }
    while(!q[cur].empty()){
        node tmp = q[cur].front();
        q[cur].pop();
        for(int i=0;i<6;i++){
            tz = tmp.z+dz[i];
            tx = tmp.x+dx[i];
            ty = tmp.y+dy[i];
            if(graph[tz][tx][ty] == 1){
                graph[tz][tx][ty] = 2;
                q[!cur].push({tz,tx,ty});
                remain--;
            }
        }
        if(q[cur].empty()){
            ans++;
            cur = !cur;
        }
    }
    if(remain==0) cout << ans-1;
    else cout << -1;
}