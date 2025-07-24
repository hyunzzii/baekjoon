#include <iostream>
using namespace std;

int N, arr[1000], dp[1000], idx=0;

void change(int s, int e, int target){
    int mid;
    while(s<e){
        mid = (s+e)/2;
        if(dp[mid] >= target){
            e = mid;
        }else{
            s = mid + 1;
        }
    }
    dp[e] = target;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    dp[0] = arr[0];
    for(int i=1;i<N;i++){
        if(dp[idx] < arr[i]){
            dp[++idx] = arr[i];
        }else{
            change(0,idx,arr[i]);
        }
    }
    cout << idx + 1;
}