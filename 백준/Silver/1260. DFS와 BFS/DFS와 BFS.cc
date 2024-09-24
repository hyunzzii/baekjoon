#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int queue[1001],s=0,e=0;

void DFS(int num){
    cout << num << " ";
    visited[num] = 1;
    for(int v: graph[num]){
        if(!visited[v]){
            DFS(v);
        }
    }
}

void BFS(int num){
    cout << num << " ";
    for(int v: graph[num]){
        if(!visited[v]){
            visited[v] = 1;
            queue[e++] = v;
        }
    }
    while(s<e){
        BFS(queue[s++]);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m,s;
    int u,v;
    cin >> n >> m >> s;
    graph.resize(n+1);
    while(m--){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    visited.resize(n+1,0);
    DFS(s);
    cout << "\n";

    visited.assign(n+1,0);
    visited[s]=1;
    BFS(s);
}