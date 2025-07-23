#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, dp[31]={0,};
    cin >> n;
    dp[2] = 3;
    for(int i=4;i<=n;i+=2){
        for(int j=2;j<i;j+=2){
            dp[i] += 2*dp[i-j];
        }
        dp[i] += dp[i-2] + 2;
    }
    cout << dp[n];
}