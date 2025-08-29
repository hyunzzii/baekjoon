#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> board = vector<vector<int>>(n+1,vector<int>(n+1));
    vector<vector<int>> arr = vector<vector<int>>(n+1,vector<int>(n+1,INT_MAX));
    vector<vector<int>> brr = vector<vector<int>>(n+1,vector<int>(n+1,0));

    char c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> c;
            board[i][j] = c-'0';
        }
    }
    deque<pair<int,int>> q;
    q.push_front({1,1});
    arr[1][1] = 0;
    int x,y,tx,ty;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop_front();
        for(int i=0;i<4;i++){
            tx = x + dx[i];
            ty = y + dy[i];
            if(tx<=0 || tx > n || ty<=0 || ty > n) continue;
            if(board[tx][ty]){
                if(arr[x][y] < arr[tx][ty]){
                    arr[tx][ty] = arr[x][y];
                    brr[tx][ty] = brr[x][y];
                    q.push_front({tx,ty});
                }
            }else{
                if(arr[x][y] + 1 < arr[tx][ty]){
                    arr[tx][ty] = arr[x][y] + 1;
                    brr[tx][ty] = brr[x][y] + 1;
                    q.push_back({tx,ty});
                }
            }
        }
    }
    cout << brr[n][n];
}