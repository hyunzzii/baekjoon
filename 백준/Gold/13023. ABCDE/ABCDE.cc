#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge;
vector<int> node;

int flag=0;
void DFS(int num, int c){
    if(c >= 5 || flag){
        flag=1;
        return;
    }

    node[num]=1;
    for(int v : edge[num]){
        if(!node[v]){
            DFS(v,c+1);
        }
    }
    node[num]=0;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m,u,v;
    cin >> n >> m;
    node.resize(n,0);
    edge.resize(n);

    while(m--){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for(int i=0;i<n;i++){
        if(!flag){
            DFS(i,1);
        }
    }
    if(flag){
        cout << 1;
    }else{
        cout << 0;
    }
}