#include <algorithm>
#include <iostream>
using namespace std;

int n,m;
int arr[9];

void func(int num, int index){
    arr[index] = num;

    if(index == m-1){
        for(int i=0;i<=index;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    if(n-num < m-1-index) return;

    for(int i=num+1; i<n+1; i++){
        func(i,index+1);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        func(i, 0);
    }    
}