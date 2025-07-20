#include <iostream>
using namespace std;

int n;
int arr[10001] = {0,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr[1] = 1;
    arr[2] = 3;
    for(int i=3;i<=n;i++){
        arr[i] = (arr[i-1] + arr[i-2]*2) % 10007;
    }
    cout << arr[n];
}