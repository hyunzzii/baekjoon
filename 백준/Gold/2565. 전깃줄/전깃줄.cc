#include <iostream>
#include <algorithm>
using namespace std;

int N, dp[501], len=0;
pair<int,int> arr[101];

void change(int s, int e, int target){
    while(s<e){
        int mid = (s+e)/2;
        if(dp[mid] < target) s = mid+1;
        else e = mid;
    }
    dp[e] =  target;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+N);
    dp[0] = arr[0].second;
    for(int i=1;i<N;i++){
        if(dp[len] < arr[i].second) dp[++len] = arr[i].second;
        else change(0,len,arr[i].second);
    }
    cout << N-(len+1);
}