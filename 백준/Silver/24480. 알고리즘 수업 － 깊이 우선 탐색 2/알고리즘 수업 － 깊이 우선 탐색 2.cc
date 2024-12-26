#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,r;
vector<vector<int>> tree;
int visited[100001] = {0,};

int num = 1;
void DFS(int cur){
    visited[cur] = num++;
    for(int v: tree[cur]){
        if(!visited[v]){
            DFS(v);
        }
    }
}

bool compare(int a, int b){
    return a>b;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    tree.resize(n+1);

    int u,v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        sort(tree[i].begin(),tree[i].end(),compare);
    }
    DFS(r);

    for(int i=1;i<=n;i++){
        cout << visited[i] << "\n";
    }
} 