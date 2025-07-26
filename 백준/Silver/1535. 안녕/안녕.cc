#include <iostream>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, hp[100][2], dp[100] = {0,};
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> hp[i][0];
    }
    for(int i=1;i<=N;i++){
        cin >> hp[i][1];
    }
    for(int i=1;i<=N;i++){
        for(int j=99;j>=0;j--){
            if(hp[i][0] <= j)
                dp[j] = max(dp[j-hp[i][0]] + hp[i][1], dp[j]);
        }
    }
    cout << dp[99];
}