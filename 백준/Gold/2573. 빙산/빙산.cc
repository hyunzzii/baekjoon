#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr[302][302], brr[302][302] = {0,};
vector<vector<bool>> visited;

int dfs(int x, int y){
    visited[x][y] = true;
    int sum = 1;
    for(int i=0;i<4;i++){
        int tx = x+dx[i];
        int ty = y+dy[i];
        if(arr[tx][ty] && !visited[tx][ty]){
            sum += dfs(tx,ty);
        }
    }
    return sum;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    int ans=0,num=0,tx,ty,ux,uy;
    cin >> N >> M;
    visited = vector<vector<bool>>(N+2, vector<bool>(M+2));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(!arr[i][j]) continue;
            num++;
            for(int k=0;k<4;k++){
                tx = i+dx[k];
                ty = j+dy[k];
                if(!arr[tx][ty]) brr[i][j]++;
            }
        }
    }
    int dx[2] = {1,0};
    int dy[2] = {0,1};
    do{
        ans++;
        ux=0,uy=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                visited[i][j] = false;
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(!arr[i][j]) continue;
                arr[i][j] -= brr[i][j];
                if(arr[i][j] <= 0){
                    num--;
                    arr[i][j] = 0;
                    brr[i][j] = 0;
                    for(int k=0;k<2;k++){
                        tx = i+dx[k];
                        ty = j+dy[k];
                        if(arr[tx][ty]){
                            arr[tx][ty]++;
                            brr[tx][ty]++;
                        }
                    }
                    for(int k=0;k<2;k++){
                        tx = i-dx[k];
                        ty = j-dy[k];
                        if(arr[tx][ty]){
                            brr[tx][ty]++;
                        }
                    }
                }else{
                    ux=i, uy=j;
                }
            }
        }
    }while(ux && (dfs(ux,uy) == num));
    if(!ux) cout << 0;
    else cout << ans;
}