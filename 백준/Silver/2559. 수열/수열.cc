#include <iostream>
#include <climits>
using namespace std;

int N,K;
int arr[100001] = {0,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    int max=INT_MIN;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
        if(i >= K && max < arr[i] - arr[i-K]){
            max = arr[i] - arr[i-K];
        }
    }
    cout << max;
}