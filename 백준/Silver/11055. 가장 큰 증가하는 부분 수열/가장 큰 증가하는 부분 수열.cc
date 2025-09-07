#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,ans=0;
    int arr[1001], sum[1001]={0,};
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        sum[i] = arr[i];
        for(int j=1;j<=i;j++){
            if(arr[j] < arr[i]){
                sum[i] = max(sum[j] + arr[i], sum[i]);
            }
        }
        if(ans < sum[i]) ans=sum[i];
    }
    cout<<ans;
}