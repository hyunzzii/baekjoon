#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m,r,count=0;
vector<priority_queue<int>> graph;
vector<int> visited;

void DFS(int cur){
    visited[cur] = ++count;
    while(!graph[cur].empty()){
        int next = -graph[cur].top();
        graph[cur].pop();
        if(!visited[next]){
            DFS(next);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    graph.resize(n+1);
    visited.resize(n+1,0);

    int u,v;
    while(m--){
        cin >> u >> v;
        graph[u].push(-v);
        graph[v].push(-u);
    }

    DFS(r);
    for(int i=1;i<=n;i++){
        cout << visited[i] << "\n";
    }
} 