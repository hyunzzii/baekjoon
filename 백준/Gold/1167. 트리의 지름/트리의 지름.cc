#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> edge; //first가 정점, second가 거리

int v, num=0;
vector<vector<edge>> tree;
vector<int> d;

int BFS(int num){
    int max_index = num;
    queue<int> q;
    q.push(num);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(edge next: tree[cur]){
            if(!d[next.first] && next.first!=num){
                q.push(next.first);
                d[next.first] = d[cur] + next.second;
                if(d[max_index] < d[next.first]){
                    max_index = next.first;
                }
            }
        }
    }
    return max_index;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v;
    tree.resize(v+1);
    d.resize(v+1,0);

    int node,u,l;
    for(int i=0;i<v;i++){
        cin >> node;
        cin >> u;
        while(u>0){
            cin >> l;
            tree[node].push_back(make_pair(u,l));
            cin >> u;
        }
    }
    int m = BFS(1);
    fill(d.begin(),d.end(),0);
    int result = BFS(m);
    cout << d[result];
} 