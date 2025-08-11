#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct node{
    int a,b,c;
}node;

bool compare(node a, node b){
    return a.c < b.c;
}

int root[100001] = {0,};

int find(int r){
    if(root[r] == r)return r;
    return root[r] = find(root[r]);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,a,b,c;
    cin >> N >> M;
    vector<node> arr;
    for(int i=0;i<M;i++){
        cin >> a >> b >> c;
        arr.push_back({a,b,c});
    }
    for(int i=1;i<=N;i++){
        root[i] = i;
    }
    sort(arr.begin(), arr.end(),compare);
    long long sum=0, ans;
    int ta, tb;
    for(int i=0;i<M;i++){
        ta = find(arr[i].a);
        tb = find(arr[i].b);
        if(ta < tb) root[tb] = ta;
        else if(ta > tb) root[ta] = tb;
        else continue;
        ans = sum;
        sum+=arr[i].c;
    }
    cout << ans;
}