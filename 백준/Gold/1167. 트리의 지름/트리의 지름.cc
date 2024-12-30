#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> node; //first가 정점, second가 거리

int v, child_max=0;
vector<vector<node>> tree;
bool visited[100001] = {0,};

int DFS(int cur){
    int result[2] = {0,}, tem = 0;
    for(node next: tree[cur]){
        if(!visited[next.first]){
            visited[next.first] = true;
            tem = DFS(next.first) + next.second;
            if(tem > result[1]){
                if(tem > result[0]){
                    result[1] = result[0];
                    result[0] = tem;
                }
                else{
                    result[1] = tem;
                }
            }
        }
    }
    if(result[0]+result[1] > child_max){
        child_max = result[0]+result[1];
    }
    return result[0];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v;
    tree.resize(v+1);

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
    visited[1] = true;
    int result = DFS(1);
    cout << max(result, child_max);
} 