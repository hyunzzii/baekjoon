#include <iostream>
using namespace std;
typedef long long ll;
#define mod 1000000000

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int arr[101][12] = {0,};
    cin >> N;

    for(int j=2;j<=10;j++){
        arr[1][j] = 1;
    }
    for(int i=2;i<=N;i++){
        for(int j=1;j<=10;j++){
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % mod;
        }
    }

    ll sum = 0;
    for(int j=1;j<=10;j++){
        sum = (sum + arr[N][j]) % mod;
    }
    cout << sum;
}