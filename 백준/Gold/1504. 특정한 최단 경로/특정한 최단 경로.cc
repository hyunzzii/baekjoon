#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct node{
    int n,v;
    bool operator<(const node& other) const {
        return v > other.v;
    }
}node;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,E;
    int a,b,c,u,v;
    priority_queue<node> pq;
    cin >> N >> E;
    vector<vector<node>> arr = vector<vector<node>>(N+1);
    for(int i=0;i<E;i++){
        cin >> a >> b >> c;
        arr[a].push_back({b,c});
        arr[b].push_back({a,c});
    }
    cin >> u >> v;
    vector<vector<int>> result = vector<vector<int>>(3,vector<int>(N+1,2000001));
    pq.push({1,0});
    while(!pq.empty()){
        node cur = pq.top();
        pq.pop();
        for(node c: arr[cur.n]){
            int tmp = cur.v + c.v;
            if(tmp < result[0][c.n]){
                result[0][c.n] = tmp;
                pq.push({c.n, tmp});
            }
        }
    }
    result[0][1] = 0;
    pq.push({N,0});
    while(!pq.empty()){
        node cur = pq.top();
        pq.pop();
        for(node c: arr[cur.n]){
            int tmp = cur.v + c.v;
            if(tmp < result[1][c.n]){
                result[1][c.n] = tmp;
                pq.push({c.n, tmp});
            }
        }
    }
    result[1][N] = 0;
    pq.push({u,0});
    while(!pq.empty()){
        node cur = pq.top();
        pq.pop();
        for(node c: arr[cur.n]){
            int tmp = cur.v + c.v;
            if(tmp < result[2][c.n]){
                result[2][c.n] = tmp;
                pq.push({c.n, tmp});
            }
        }
    }
    int t1 = result[0][u] + result[1][v];
    int t2 = result[0][v] + result[1][u];
    int ans = min(t1,t2)+result[2][v];
    if(ans >= 2000001) cout << -1;
    else cout << ans;
}