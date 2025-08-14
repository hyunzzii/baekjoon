#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,n;
    unsigned int arr[1000001] = {0,};
    arr[1] = 1, arr[2] = 2, arr[3] = 4;
    for(int i=4;i<=1000000;i++){
        arr[i] = (arr[i-3] + arr[i-2] + arr[i-1]) % 1000000009;
    }
    cin >> T;
    while(T--){
        cin >> n;
        cout << arr[n] << "\n";
    }
}