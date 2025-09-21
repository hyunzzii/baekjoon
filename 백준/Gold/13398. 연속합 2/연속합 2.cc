#include <iostream>
using namespace std;
typedef long long ll;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, arr[100001] = {0,}, tmp0, tmp1, rflag=0;
    ll sum[100001][2] = {0,}, ans;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    ans = arr[0];
    sum[0][0] = ans, sum[0][1] = ans;
    for(int i=1;i<n;i++){
        if(arr[i] > 0){
            tmp0 = sum[i-1][0] + arr[i];
            tmp1 = sum[i-1][1] + arr[i];
        }
        else{
            if(rflag){
                tmp0 = max(sum[i-1][1], sum[i-1][0] + arr[i]);
                tmp1 = sum[i-1][1] + arr[i];
            }else{
                rflag=1;
                tmp0 = sum[i-1][0];
                tmp1 = sum[i-1][0] + arr[i];
            }
        }
        if(tmp0 < arr[i]){
            tmp0 = arr[i];
            tmp1 = arr[i];
            rflag=0;
        }
        else if(tmp1 < arr[i]){
            tmp1 = arr[i];
        }
        sum[i][0] = tmp0;
        sum[i][1] = tmp1;
        if(ans < sum[i][0]) ans = sum[i][0];
    }
    cout << ans;
}