#include <iostream>
using namespace std;

long long n,k;

long long search(long long num){
    long long s=1, e=n;
    while(s<=e){
        long mid = (s+e)/2;
        if(n*mid <= num){
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    return e;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;

    long long s=1,e=n*n;
    while(s <= e){
        long long sum=0,num;
        long long mid = (s+e)/2;
        num = search(mid);
        sum+=num;
        for(int i=n-1;i>0;i--){
            while(i*num<=mid && num <=n){
                num++;
            }
            num--;
            sum += num;
        }
        if(sum<k){
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    cout << s;
} 