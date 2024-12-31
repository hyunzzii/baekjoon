#include <iostream>
#include <vector>
using namespace std;

int n, sum = 0, arr[16][16] = {0,};

void DFS(int x){
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
                DFS(next);
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    DFS(0);
    cout << sum;
} 