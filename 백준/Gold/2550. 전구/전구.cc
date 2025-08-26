#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> t;
int find(int n){
    int s = 0;
    int e = t.size()-1 < 0 ? 0 : t.size()-1;
    while(s<e){
        int mid = (s+e)/2;
        if(t[mid].first >= n) e = mid;
        else s = mid + 1;
    }
    return e;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, tmp;
    cin >> N;
    vector<int> sch = vector<int>(N+1);
    vector<int> light = vector<int>(N+1);
    vector<int> arr = vector<int>(N+1);

    for(int i=1;i<=N;i++){
        cin >> tmp;
        sch[tmp] = i;
    }
    for(int i=1;i<=N;i++){
        cin >> tmp;
        light[i] = tmp;
        arr[i] = sch[tmp]; 
    }

    int root[10001];
    for(int i=1;i<=N;i++){
        root[i] = i;
    }
    t.push_back({arr[1],1});
    for(int i=2;i<=N;i++){
        if(arr[i] > t[t.size()-1].first){
            root[i] = t[t.size()-1].second;
            t.push_back({arr[i],i});
        } else{
            int idx = find(arr[i]);
            t[idx].first = arr[i];
            t[idx].second = i;
            if(idx) root[i] = t[idx-1].second;
            else root[i] = i;
        }
    }
    int sum = t.size();
    vector<int> ans;
    tmp = t[sum-1].second;
    while(true){
        ans.push_back(light[tmp]);
        if(tmp == root[tmp])break;
        tmp = root[tmp];
    }
    sort(ans.begin(),ans.end());
    cout << sum << "\n";
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
}