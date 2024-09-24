#include <cstdio>
using namespace std;
    
int arr[100][100], v[100][100],n, h;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void search(int x, int y){
    int x1,y1;
    for(int i=0;i<4;i++){
        x1 = x+dx[i];
        y1 = y+dy[i];
        if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= n) continue;
        if(v[x1][y1]){
            v[x1][y1] = 0;
            search(x1,y1);
        }
    }
}
int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int max=1,sum;

    for(h=0;h<100;h++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]>h){
                    v[i][j]=1;
                }else{
                    v[i][j]=0;
                }
            }
        }
        sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]){
                    v[i][j]=0;
                    search(i,j);
                    sum++;
                }
            }
        }
        if(!sum) break;
        if(max < sum) max = sum;
    }
    printf("%d",max);
} 