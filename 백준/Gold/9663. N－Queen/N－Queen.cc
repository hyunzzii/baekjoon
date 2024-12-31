#include <cstdio>
using namespace std;

int n, sum = 0, arr[16][16] = {0,};
void q(int x){
    if(x==n){
        sum++;
        return;
    }else{
        for(int col=1;col<=n;col++){
            int next = x+1;
            if(!arr[next][col]){
                for(int row=next;row<=n;row++){

                    arr[row][col]++;
                    if(col+row-next <= n){
                        arr[row][col + row - next]++;
                    }
                    if(col-row+next >= 1){
                        arr[row][col - row + next]++;
                    }
                }
                q(next);
                for(int row=next;row<=n;row++){
                    arr[row][col]--;
                    if(col+row-next <= n){
                        arr[row][col + row - next]--;
                    }
                    if(col-row+next >= 1){
                        arr[row][col - row + next]--;
                    }
                }
            }
        }
    }
}

int main(void){
    scanf("%d",&n);
    q(0);
    printf("%d",sum);
} 