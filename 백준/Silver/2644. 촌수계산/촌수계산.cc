#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> graph;

int n, m, x, y, a, b;
int visited[101] = {0,}, ans;

void dfs(int n, int target, int dept){
    visited[n] = 1;
    if(n == target) ans = dept;
    for(int v : graph[n]){
        if(!visited[v]){
            dfs(v, target, dept+1);
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> a >> b;
    cin >> m;
    graph = vector<vector<int>> (n+1,vector<int>(0));
    while(m--){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(a,b,0);
    cout << (ans > 0 ? ans : -1);
}