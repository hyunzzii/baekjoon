#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> node; //first가 정점, second가 거리

int v;
vector<vector<node>> tree;
vector<int> visited;

node DFS(int cur){
    int child_max = 0, max[2] = {0,};
    node tem, result;
    for(node next: tree[cur]){
        if(!visited[next.first]){
            visited[next.first] = 1;
            tem = DFS(next.first);
            tem.first += next.second;
            if(child_max < tem.second){
                child_max = tem.second;
            }
            if(tem.first > max[1]){
                if(tem.first > max[0]){
                    max[1] = max[0];
                    max[0] = tem.first;
                }
                else{
                    max[1] = tem.first;
                }
            }
        }
    }
    return make_pair(max[0], max[0]+max[1] > child_max? max[0]+max[1] : child_max);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v;
    tree.resize(v+1);
    visited.resize(v+1,0);

    int num,u,l;
    for(int i=0;i<v;i++){
        cin >> num;
        cin >> u;
        while(u>0){
            cin >> l;
            tree[num].push_back(make_pair(u,l));
            cin >> u;
        }
    }
    visited[1] = 1;
    node result = DFS(1);
    cout << (result.first < result.second ? result.second : result.first);
} 