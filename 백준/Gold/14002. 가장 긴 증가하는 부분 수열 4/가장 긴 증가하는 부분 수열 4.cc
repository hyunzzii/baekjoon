#include <iostream>
#include <string>
using namespace std;

int N, arr[1001], dp[1001][2] = {0,}, l[1001] = {0,};
string s = "";

void change(int s, int e, int i){
    while(s < e){
        int mid = (s+e)/2;
        if(dp[mid][0] < arr[i]) s = mid + 1;
        else e = mid;
    }
    if(arr[i] == dp[e][0]) l[i] = -1;
    else{
        l[i] = dp[e-1][1];
        dp[e][0] = arr[i];
        dp[e][1] = i;
    }
}

int dfs(int n){
    if(l[n] < 0) return 0;
    if(l[n] == 0) return 1;
    else return dfs(l[n]) + 1;
}

void print(int i){
    s = to_string(arr[i]) + ' ' + s;
    if(l[i] == 0){
        cout << s;
        return;
    }
    print(l[i]);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    int len = 1;
    dp[1][0] = arr[1];
    dp[1][1] = 1;
    l[1] = 0;
    for(int i=2;i<=N;i++){
        if(dp[len][0] < arr[i]){
            dp[++len][0] = arr[i];
            dp[len][1] = i;
            l[i] = dp[len-1][1];
        }
        else change(0, len, i);
    }
    cout << len << "\n";
    for(int i=N;i>0;i--){
        if(dfs(i) == len){
            print(i);
            break;
        }
    }
}