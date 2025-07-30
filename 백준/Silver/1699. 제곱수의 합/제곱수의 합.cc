#include <iostream>
#include <cmath>
using namespace std;
int min(int a, int b){
    return a<b && a!=0 ? a : b;
}

int dp[100001] = {0,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    dp[1] = 1;
    for(int i=1;i<=N;i++){
        int tmp = sqrt(i);
        if(tmp * tmp == i){
            dp[i] = 1;
            continue;
        }
        for(int j=1;j<=i/2;j++){
            dp[i] = min(dp[i], dp[j] + dp[i-j]);
        }
    }
    cout << dp[N];
}