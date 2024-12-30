#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    vector<vector<int>> dp(n+1,vector<int>(k+1,0));

    for(int i=1;i<=n;i++){
        dp[i][1] = 1;
    }
    for(int j=1;j<=k;j++){
        dp[0][j] = 1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=2;j<=k;j++){
            for(int l=0;l<=i;l++){
                dp[i][j] += dp[l][j-1];
                dp[i][j] %= 1000000000;
            }
        }
    }
    cout << dp[n][k];
} 