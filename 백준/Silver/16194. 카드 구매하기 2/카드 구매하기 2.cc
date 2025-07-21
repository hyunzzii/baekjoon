#include <iostream>
using namespace std;
int min(int a, int b){
    return a < b ? a : b;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int arr[1001] = {0,};

    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        for(int j=1;j<=i/2;j++){
            arr[i] = min(arr[i], arr[j] + arr[i-j]);
        }
    }
    cout << arr[N];
}