#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned k,n;
    cin >> k >> n;
    vector<unsigned> arr(n,0);
    unsigned s=1,e=0;
    for(int i=0;i<k;i++){
        cin >> arr[i];
        if(e < arr[i]){
            e= arr[i];
        }
    }
    while(s <= e){
        int sum=0;
        unsigned mid = (s+e)/2;
        for(int i=0;i<k;i++){
            sum += (arr[i]/mid);
        }
        if(sum < n){
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    cout << e;
} 