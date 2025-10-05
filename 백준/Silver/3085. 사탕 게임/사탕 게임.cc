#include <iostream>
using namespace std;

int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

int n;
char arr[52][52] = {0,};

int search(){
    int sum[52][52] = {0,}, ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i+1][j] == arr[i][j]) sum[i+1][j] = sum[i][j]+1;
            if(sum[i+1][j] > ans) ans = sum[i+1][j];
        }
    }
    int sum2[52][52] = {0,};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j+1] == arr[i][j]) sum2[i][j+1] = sum2[i][j]+1;
            if(sum2[i][j+1] > ans) ans = sum2[i][j+1];
        }
    }
    return ans+1;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    int ans = 1, sum, tmp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<2;k++){
                int tx = i + dx[k];
                int ty = j + dy[k];
                if(arr[tx][ty] && arr[tx][ty] != arr[i][j]){
                    tmp = arr[i][j];
                    arr[i][j] = arr[tx][ty];
                    arr[tx][ty] = tmp;
                    if((sum = search()) > ans) ans = sum;
                    tmp = arr[i][j];
                    arr[i][j] = arr[tx][ty];
                    arr[tx][ty] = tmp;
                }
            }
        }
    }
    cout << ans;
}