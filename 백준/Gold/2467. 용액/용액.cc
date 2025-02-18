#include <iostream>
#include <cstdlib>
using namespace std;

int compare(int a, int b){
    return abs(a) < abs(b);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,arr[100000]={0,},ans[2];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int left=0,right=n-1,sum,min=2000000001;
    while(left < right){
        sum = arr[left]+arr[right];
        if(abs(sum) < min){
            min = abs(sum);
            ans[0] = arr[left];
            ans[1] = arr[right];
        }
        sum<0 ? left++:right--;
    }
    cout << ans[0]<<" "<<ans[1];
}