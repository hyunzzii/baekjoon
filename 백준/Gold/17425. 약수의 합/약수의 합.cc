#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max = 1000000;
    unsigned long ans[1000001] = {0,};
    ans[1]=1;
    for(int i=2;i<=max;i++){
        ans[i] += 1 + i;
        for(int j=2;i*j<=max;j++){
            ans[i*j]+=i;
        }
    }
    for(int i=1;i<=max;i++){
        ans[i] += ans[i-1];
    }
    int t,tmp;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> tmp;
        cout << ans[tmp]<<"\n";
    }
}