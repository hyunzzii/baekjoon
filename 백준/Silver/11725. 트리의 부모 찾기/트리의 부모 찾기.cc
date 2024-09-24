#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> parent;
stack<int> s;

void search(){
    int now = s.top();
    s.pop();
    visited[now] = 1;
    for(int v: graph[now]){
        if(!visited[v]){
            parent[v] = now;
            visited[v] = 1;
            s.push(v);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,u,v;
    cin >> n;
    parent.resize(n+1,0);
    visited.resize(n+1,0);
    graph.resize(n+1);
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    s.push(1);
    do{
        search();
    }while(!s.empty());

    for(int i=2;i<=n;i++){
        cout << parent[i] << "\n";
    }
}