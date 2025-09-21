#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, arr[100001] = {0,}, sum0, sum1, ans;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    ans = arr[0];
    sum0 = ans, sum1 = ans;
    for(int i=1;i<n;i++){
        sum0 = max(arr[i], max(sum0 + arr[i], sum1));
        sum1 = max(sum1 + arr[i], arr[i]);
        if(ans < sum0) ans = sum0;
    }
    cout << ans;
}