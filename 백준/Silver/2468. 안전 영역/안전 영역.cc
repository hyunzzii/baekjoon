#include <iostream>
#include <queue>
using namespace std;
    
int arr[100][100], v[100][100], n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int,int>> que;

void BFS(int x, int y){
    v[x][y] = 0;
    que.push(make_pair(x,y));
    int x1,y1;
    while(!que.empty()){
        x = que.front().first;
        y = que.front().second;
        que.pop();

        for(int i=0;i<4;i++){
            x1 = x+dx[i];
            y1 = y+dy[i];
            if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= n) continue;
            if(v[x1][y1]){
                v[x1][y1] = 0;
                que.push(make_pair(x1,y1));
            }
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    int max=1;

    for(int h=0;h<100;h++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]>h){
                    v[i][j]=1;
                }
                else{
                    v[i][j]=0;
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]){
                    BFS(i,j);
                    sum++;
                }
            }
        }
        if(!sum) break;
        if(max < sum) max = sum;
    }
    cout << max;
} 