#include <iostream>
using namespace std;

long long min(int a, int b){
    return a <= b ? a : b;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n,k,s,e,sum,mid;
    cin >> n >> k;
    s=1, e=k;
    while(s <= e){
        sum=0;
        mid = (s+e)/2;
        int i;
        for(i=1;i*i<=mid;i++){
            sum += min(mid/i,n);
        }
        i--;
        sum = 2*sum - i*i;
        if(sum<k){
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    cout << s;
} 