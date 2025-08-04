#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ipair;

queue<ipair> q[2];
vector<vector<int>> graph;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M,N;
    cin >> M >> N;
    graph = vector<vector<int>>(N+2,vector<int>(M+2,0));

    int x,y,remain=0, cur=0, ans=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> graph[i][j];
            graph[i][j]++;
            if(graph[i][j]==1) remain++;
            else if(graph[i][j]==2) q[cur].push({i,j});
        }
    }
    while(!q[cur].empty()){
        pair<int,int> tmp = q[cur].front();
        q[cur].pop();
        for(int i=0;i<4;i++){
            x = tmp.first+dx[i];
            y = tmp.second+dy[i];
            if(graph[x][y] == 1){
                graph[x][y] = 2;
                q[!cur].push({x,y});
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