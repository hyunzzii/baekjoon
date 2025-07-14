#include <iostream>
using namespace std;

int n,sum=0;
int arr[15][15] = {0,};

void func(int row){
    if(row > n){
        sum++;
        return;
    }
    for(int col=1;col<=n;col++){
        if(!arr[row][col]){
            for(int i=0;row+i<=n;i++){
                arr[row+i][col]++;
                if(col-i>0) arr[row+i][col-i]++;
                if(col+i<=n) arr[row+i][col+i]++;
            }
            func(row+1);
            for(int i=0;row+i<=n;i++){
                arr[row+i][col]--;
                if(col-i>0) arr[row+i][col-i]--;
                if(col+i<=n) arr[row+i][col+i]--;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    func(1);
    cout << sum;
}