#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> graph;

int n, m, x, y, a, b;
int visited[101] = {0,}, flag=0, ans=-1;

void dfs(int n, int target, int dept){
    visited[n] = 1;
    if(n == target){
        flag=1;
        ans += dept;
    }
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
    int parent[101] = {0,};
    while(m--){
        cin >> x >> y;
        graph[x].push_back(y);
        parent[y] = x;
    }
    int p = a;
    while(p && !flag){
        ans++;
        if(p == b){
            flag = 1;
            break;
        }
        dfs(p, b, 0);
        p = parent[p];
    }
    if(flag) cout << ans;
    else cout << -1;

}