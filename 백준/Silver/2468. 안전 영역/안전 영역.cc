#include <iostream>
#include <vector>
using namespace std;
    
vector<vector<int>> arr;
int n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void search(int x, int y, int h, vector<vector<int>> &visited){
    for(int i=0;i<4;i++){
        int x1 = x+dx[i];
        int y1 = y+dy[i];
        if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= n) continue;
        if(arr[x1][y1]>=h && !visited[x1][y1]){
            visited[x1][y1] = 1;
            search(x1,y1,h,visited);
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int height[101]={0,};
    
    cin >> n;
    arr.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    int x=0,y=0,max=1;
    while(true){
        vector<vector<int>> visited(n,vector<int>(n));
        int sum=0,flag=0;

        while(x<n){
            while(y<n){
                if(!height[arr[x][y]]){
                    flag = 1;
                    break;
                }
                y++;
            }
            if(flag) break;
            y = 0;
            x++;
        }
        if(!flag) break;
        int h = arr[x][y];
        height[h] = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]>=h && !visited[i][j]){
                    visited[i][j] = 1;
                    search(i,j,h,visited);
                    sum++;
                }
            }
        }
        if(max < sum) max = sum;
    }
    cout << max;
} 