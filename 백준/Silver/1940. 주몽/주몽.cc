#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int N,M;
    int sum=0,tem;
    int num[100001] = {0,};
    
    cin >> N >> M;
    if(M/2 > 100000){
        cout << sum;
         return 0;
    }
    
    while(N--){
        cin >> tem;
        num[tem] = 1;
    }
    for(int i=1;i<(double)M/2;i++){
        if(num[i]!=1) continue;
        if(num[M-i]==1){
            sum++;
        }
    }
    cout << sum;
}