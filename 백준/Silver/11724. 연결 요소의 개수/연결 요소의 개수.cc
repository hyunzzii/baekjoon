#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
int arr[1001] = {0,}, stack[1000], top=0, cmpl=0;

void visit(int num, int index){
    int tem;
    for(int i=0;i<adj[num].size();i++){
        tem = adj[num][i];
        if(!arr[tem]){
            stack[top++] = tem;
            arr[tem] = index;
            cmpl++;
        }
    }
    if(!top){
        return;
    }
    visit(stack[--top], index);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m,u,v;
    cin >> n >> m;

    for(int i=0;i<=n;i++){
        vector<int> tem(1,i);
        adj.push_back(tem);
    }

    while(m--){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int index=0,s;
    do{
        for(s=1;s<=n;s++){
            if(!arr[s]) break;
        }
        visit(s,++index);
    }while(cmpl<n);

    cout << index;
}