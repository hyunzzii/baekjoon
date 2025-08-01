#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int dp[27][27], sum[600] = {0,}, num=2;

void dfs(int x, int y){
    for(int i=0;i<4;i++){
        if(dp[x+dx[i]][y+dy[i]] == 1){
            dp[x+dx[i]][y+dy[i]] = dp[x][y];
            sum[num-2]++;
            dfs(x+dx[i],y+dy[i]);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    char input[27][27];
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> input[i][j];
            dp[i][j] = input[i][j] - '0';
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(dp[i][j] == 1){
                dp[i][j] = num;
                sum[num-2]++;
                dfs(i,j);
                num++;
            }
        }
    }
    sort(sum, sum+num-2);
    cout << num-2 << "\n";
    for(int i=0;i<num-2;i++){
        if(!sum[i]) continue;
        cout << sum[i] << "\n";
    }
}