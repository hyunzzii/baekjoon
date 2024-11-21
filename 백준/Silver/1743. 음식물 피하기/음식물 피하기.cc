#include <cstdio>
using namespace std;

int n,m,k;
int arr[102][102] = {0,};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int DFS(int row, int col, int cnt){
    arr[row][col] = 0;
    for(int i=0;i<4;i++){
        int n_row = row + dx[i];
        int n_col = col + dy[i];
        if(arr[n_row][n_col]){
            cnt = DFS(n_row,n_col,cnt+1);
        }
    }
    return cnt;
}

int main(void){
    scanf("%d %d %d",&n,&m,&k);
    
    int r,c;
    while(k--){
        scanf("%d %d",&r,&c);
        arr[r][c] = 1;
    }

    int max= 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]){
                int tem = DFS(i,j,1);
                if(max<tem){
                    max = tem;
                }
            }
        }
    }
    printf("%d",max);
} 