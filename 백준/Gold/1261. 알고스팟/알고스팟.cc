#include <iostream>
#include <queue>
#include <climits>
using namespace std;
typedef struct node{
    int x,y,v;
    bool operator<(const node& other) const {
        return v > other.v;
    }
}node;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    int N,M;
    char c;
    cin >> M >> N;
    int arr[101][101], dp[101][101];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> c;
            arr[i][j] = c - '0';
            dp[i][j] = INT_MAX;
        }
    }
    priority_queue<node> pq;
    dp[1][1] = 0;
    pq.push({1,1,0});
    int tx,ty;
    node cur;
    while(!pq.empty()){
        cur = pq.top();
        pq.pop();
        for(int i=0;i<4;i++){
            tx = cur.x + dx[i];
            ty = cur.y + dy[i];
            if(tx<1 || tx>N || ty<1 || ty>M) continue;
            if(arr[tx][ty]){
                if(dp[cur.x][cur.y] + 1 < dp[tx][ty]){
                    dp[tx][ty] = dp[cur.x][cur.y] + 1;
                    pq.push({tx,ty,dp[tx][ty]});
                }
            }else{
                if(dp[cur.x][cur.y] < dp[tx][ty]){
                    dp[tx][ty] = dp[cur.x][cur.y];
                    pq.push({tx,ty,dp[tx][ty]});
                }
            }
        }
    }
    cout << dp[N][M];
}