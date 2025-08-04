#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int,int> ipair;
vector<vector<int>> arr,trr;
vector<ipair> virus;

int dfs(){
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    stack<ipair> s;
    for(ipair v : virus){
        s.push(v);
    }
    int x,y,tx,ty,sum=0;
    while(!s.empty()){
        x = s.top().first;
        y = s.top().second;
        s.pop();
        for(int i=0;i<4;i++){
            tx = x+dx[i];
            ty = y+dy[i];
            if(!trr[tx][ty]){
                trr[tx][ty]=2;
                sum++;
                s.push({tx,ty});
            }
        }
    }
    return sum;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,max=0,tmp,remain=0;
    cin >> N >> M;
    arr = vector<vector<int>>(N+2,vector<int>(M+2,1)); 
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> arr[i][j];
            if(arr[i][j]==2) virus.push_back({i,j});
            else if(!arr[i][j])remain++;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(arr[i][j]) continue;
            arr[i][j] = 1;
            for(int k=1;k<=i;k++){
                for(int l=1;(k<i&&l<=M)||l<=j;l++){
                    if(arr[k][l]) continue;
                    arr[k][l] = 1;
                    for(int m=1;m<=k;m++){
                        for(int n=1;(m<k&&n<=M)||n<=l;n++){
                            if(arr[m][n]) continue;
                            arr[m][n] = 1;
                            trr = arr;
                            tmp = remain - dfs() - 3;
                            if(max < tmp) max = tmp;
                            arr[m][n] = 0;
                        }
                    }
                    arr[k][l] = 0;
                }
            }
            arr[i][j] = 0;
        }
    }
    cout << max;
}