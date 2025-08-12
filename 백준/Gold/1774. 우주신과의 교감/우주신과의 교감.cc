#include <iostream>
#include <vector>
#include <algorithm>
// #include <cstdio>
// #include <stack>
// #include <queue>
// #include <cstdlib>
// #include <set>
#include <cmath>
// #include <string>
// #include <climits>
#include <iomanip>
using namespace std;
typedef struct node{
    int a,b;
    double value;
}node;

vector<node> arr;
bool compare(node a, node b){
    return a.value < b.value;
}

int root[1001] = {0,};

int find(int r){
    if(root[r] == r)return r;
    return root[r] = find(root[r]);
}

double caculate(int x1, int y1, int x2, int y2){
    long long dx = abs(x1-x2);
    long long dy = abs(y1-y2);
    return sqrt(dx*dx+dy*dy);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,x,y;
    cin >> N >> M;
    int cord[1001][2];
    for(int i=1;i<=N;i++){
        root[i] = i;
    }
    for(int i=0;i<N;i++){
        cin >> cord[i][0] >> cord[i][1];
        for(int j=0;j<i;j++){
            arr.push_back({j+1,i+1,caculate(cord[i][0], cord[i][1], cord[j][0], cord[j][1])});
        }
    }
    sort(arr.begin(),arr.end(),compare);
    int ta, tb;
    double ans = 0;
    for(int i=0;i<M;i++){
        cin >> x >> y;
        ta = find(x);
        tb = find(y);
        if(ta < tb) root[tb] = ta;
        else root[ta] = tb;
    }
    for(int i=0;i<arr.size();i++){
        ta = find(arr[i].a);
        tb = find(arr[i].b);
        if(ta < tb) root[tb] = ta;
        else if(ta > tb) root[ta] = tb;
        else continue;
        ans += arr[i].value;
    }
    cout << fixed << setprecision(2) << ans;
}