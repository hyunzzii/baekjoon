#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int queue[1001],s=0,e=0;

void DFS(int num){
    printf("%d ",num);
    visited[num] = 1;
    for(int v: graph[num]){
        if(!visited[v]){
            DFS(v);
        }
    }
}

void BFS(int num){
    printf("%d ",num);
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
    int n,m,s;
    int u,v;
    scanf("%d %d %d",&n,&m,&s);
    graph.resize(n+1);
    while(m--){
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    visited.resize(n+1,0);
    DFS(s);
    printf("\n");

    visited.assign(n+1,0);
    visited[s]=1;
    BFS(s);
}