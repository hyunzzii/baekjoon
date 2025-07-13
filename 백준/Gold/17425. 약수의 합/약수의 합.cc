#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,max=1;
    cin >> t;
    vector<int> arr = vector<int>(t);
    unsigned long ans[1000001] = {0,};
    for(int i=0;i<t;i++){
        cin >> arr[i];
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
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
    for(int i=0;i<t;i++){
        cout << ans[arr[i]]<<"\n";
    }
}