#include <iostream>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, w, v;
    int dp[100001] = {0,};
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> w >> v;
        for(int j=K;j>=1;j--){
            if(w <= j){
                dp[j] = max(dp[j], dp[j-w] + v);
            }
        }
    }
    cout << dp[K];
}