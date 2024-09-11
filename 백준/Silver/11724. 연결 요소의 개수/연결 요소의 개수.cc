#include <iostream>
using namespace std;

int parents[1001];
int find(int n){
    if(parents[n] != n){
        parents[n] = find(parents[n]);
    }
    return parents[n];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m,u,v,result=0;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        parents[i] = i;
    }

    while(m--){
        cin >> u >> v;
        u=find(u);
        v=find(v);
        if(u!=v){
           parents[v] = parents[u];
        }
        // 부모요소를 찾아서, 각각의 부모요소끼리 연결
    }
    for(int i=1;i<=n;i++){
        if(parents[i]==i){
            result++;
        }
    }
    cout << result;
}
