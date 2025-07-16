#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAXSUM 3000000001

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, arr[5000]={0,};

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int left, right, ans[3], a, b;
    ll min=MAXSUM, sum, tmp;
    for(int i=0;i<n-2;i++){
        left = i+1;
        right = n-1;
        sum = MAXSUM;
        while(left < right){
            tmp = arr[left] + arr[right] + (ll)arr[i];
            if(abs(tmp) < sum){
                sum = abs(tmp);
                a = left;
                b = right;
            }
            if(!tmp) break;
            else if(tmp > 0) right--;
            else left++;
        }
        if(sum < min){
            min = sum;
            ans[0] = arr[i];
            ans[1] = arr[a];
            ans[2] = arr[b];
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2];
}