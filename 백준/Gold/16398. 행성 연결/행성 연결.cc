#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct node{
    int s,e,v;
    
}node;
bool compare(node a, node b){
    return a.v < b.v;
}

int root[1001];
int find(int n){
    if(n == root[n]) return n;
    else return root[n] = find(root[n]);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,s,e,v;
    long long ans=0;
    vector<node> arr;
    cin >> N;
    for(int i=1;i<=N;i++){
        root[i] = i;
        for(int j=1;j<=N;j++){
            cin >> v;
            if(!v) continue;
            arr.push_back({i,j,v});
        }
    }
    sort(arr.begin(),arr.end(),compare);

    for(int i=0;i<arr.size();i++){
        node tmp = arr[i];
        s = find(tmp.s);
        e = find(tmp.e);
        if(s==e) continue;
        if(s<e) root[e] = s;
        else root[s] = e;
        ans += tmp.v;
    }
    cout << ans;
}