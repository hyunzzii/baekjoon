#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, sum;
    cin >> N;
    int arr[100001] = {0,};
    arr[1] = 3;
    arr[2] = 7;
    for(int i=3;i<=N;i++){
        arr[i] = (arr[i-2] + 2*arr[i-1])%9901;
    }
    cout << arr[N];
}   