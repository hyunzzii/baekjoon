#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct node{
    int A,B,C;
}node;
int root[10001] = {0,};

bool compare(node a, node b){
    return a.C < b.C;
}
int find(int n){
    if(root[n] == n) return n;
    return root[n] = find(root[n]);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V,E,A,B,C;
    cin >> V >> E;
    vector<node> arr;
    for(int i=1;i<=V;i++){
        root[i] = i;
    }
    for(int i=0;i<E;i++){
        cin >> A >> B >> C;
        arr.push_back({A,B,C});
    }
    sort(arr.begin(),arr.end(),compare);
    int ans = 0,ta,tb;
    for(int i=0;i<E;i++){
        ta = find(arr[i].A);
        tb = find(arr[i].B);
        if(ta == tb) continue;
        if(ta < tb){
            root[tb] = ta;
        }else{
            root[ta] = tb;
        }
        ans += arr[i].C;
    }
    cout << ans;
}