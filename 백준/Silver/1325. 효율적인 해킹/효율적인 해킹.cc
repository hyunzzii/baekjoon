#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
vector<vector<int>> graph;

int BFS(int k){
    bool visited[10001] = {false,};
    queue<int> q;

    q.push(k);
    int sum = 1;
    visited[k] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int num: graph[cur]){
            if(!visited[num]){
                visited[num] = true;
                q.push(num);
            }
        }
        sum++;
    }
    return sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    graph.resize(n+1);
    int arr[10001]={0,};

    int a,b;
    while(m--){
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int max = 0;
    for(int i=1;i<=n;i++){
        if(!graph[i].empty()){
            int sum = BFS(i);
            arr[i] = sum;
            if(max <= sum){
                max = sum;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(arr[i] == max){
            cout << i << " ";
        }
    }
} 