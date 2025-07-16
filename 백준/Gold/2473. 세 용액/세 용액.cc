#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

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

    int base, left, right;
    int ans[3], loca[2];
    ll min=3000000001, locm, tmp;
    for(int i=0;i<n-2;i++){
        base = arr[i];
        left = i+1;
        right = n-1;
        locm = 3000000001;
        while(left < right){
            tmp = arr[left] + arr[right] + (ll)base;
            if(abs(tmp) < locm){
                locm = abs(tmp);
                loca[0] = arr[left];
                loca[1] = arr[right];
            }
            if(tmp==0){
                break;
            }else if(tmp > 0){
                right--;
            }else{
                left++;
            }
        }
        if(locm < min){
            min = locm;
            ans[0] = base;
            ans[1] = loca[0];
            ans[2] = loca[1];
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2];
}