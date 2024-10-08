#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> drawing;
int n, m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int DFS(int x, int y){
    int x1,y1,sum=1;
    for(int i=0;i<4;i++){
        x1 = x + dx[i];
        y1 = y + dy[i];
        if(x1>=0 && y1>=0 && x1<n && y1<m){
            if(drawing[x1][y1]){
                drawing[x1][y1]=0;
                sum += DFS(x1,y1);
            }
        }
    }
    return sum;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    drawing = vector<vector<int>>(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> drawing[i][j];
        }
    }
    int num=0, max=0, tem;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(drawing[i][j]==1){
                drawing[i][j] = 0;
                num++;
                tem = DFS(i,j);
                max = max < tem ? tem : max;
            }
        }
    }
    cout << num << "\n" << max;
} 