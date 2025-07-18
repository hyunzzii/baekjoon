#include <iostream>
#include <climits>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K,max=INT_MIN;
    int arr[100001] = {0,};

    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    for(int i=K;i<=N;i++){
        int tmp = arr[i] - arr[i-K];
        if(max < tmp) max = tmp;
    }
    cout << max;
}