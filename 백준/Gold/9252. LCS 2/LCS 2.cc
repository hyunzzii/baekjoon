#include <iostream>
#include <string>
using namespace std;

string a, b, ans="";
int dp[1002][1002] = {0,};

int max(int a, int b){
    return a > b ? a : b;
}

void dfs(int x, int y){
    if(!dp[x][y]){
        cout << dp[a.length()][b.length()] << "\n";
        cout << ans <<"\n";
        return;
    }
    if(dp[x][y-1] == dp[x][y]) dfs(x,y-1);
    else if(dp[x-1][y] == dp[x][y]) dfs(x-1,y);
    else{
        ans = a[x-1] + ans;
        dfs(x-1,y-1);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a;
    cin >> b;
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length();j++){
            if(a[i] == b[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    dfs(a.length(),b.length());
}