#include <iostream>
using namespace std;
int N, K;
int dp[100001][101] = {0,}, input[101][2];

int max(int a, int b){
    return a > b ? a : b;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> input[i][0] >> input[i][1];
    }
    for(int w=1;w<=K;w++){
        for(int i=1;i<=N;i++){
            if(input[i][0] <= w){
                dp[w][i] = max(dp[w][i-1], input[i][1] + dp[w-input[i][0]][i-1]);
            }else {
                dp[w][i] = dp[w][i-1];
            }
        }
    }
    cout << dp[K][N];
}