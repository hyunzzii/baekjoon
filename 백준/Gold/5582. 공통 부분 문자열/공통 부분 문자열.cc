#include <iostream>
#include <string>
using namespace std;

int dp[4001][4001] = {0,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a;
    cin >> b;
    int max=0;
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length();j++){
            if(a[i]==b[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
                if(max < dp[i+1][j+1]) max = dp[i+1][j+1];
            }
        }
    }
    cout << max;
}