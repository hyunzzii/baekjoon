#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,tmp;
    cin >> n;
    vector<vector<int>> dp = vector<vector<int>>(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin >> tmp;
            dp[i].push_back(tmp);
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + dp[i][j];
        }
    }
    cout << dp[0][0];
}