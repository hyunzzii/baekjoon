#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> ans;
void func(int num, int dept){
    if(dept == M){
        for(int i=0;i<ans.size();i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    for(int i=1;i<=N;i++){
        if(find(ans.begin(), ans.end(),i) == ans.end()){
            ans.push_back(i);
            func(i,dept+1);
            ans.pop_back();
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        ans.push_back(i);
        func(i,1);
        ans.pop_back();
    }
}