#include <iostream>
using namespace std;
typedef long long ll;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    ll arr[91];
    cin >> N;

    arr[1] = 1, arr[2] = 1;
    for(int i=3;i<=N;i++){
        arr[i] = arr[i-2] + arr[i-1];
    }
    cout << arr[N];
}