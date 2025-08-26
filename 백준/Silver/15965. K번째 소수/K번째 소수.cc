#include <iostream>
#include <cmath>
using namespace std;
#define LIMIT 8000000

int K, arr[LIMIT+1];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    int limit = sqrt(LIMIT);
    for(int i=2;i<=limit;i++){
        if(arr[i]) continue;
        for(int j=i;i*j<=LIMIT;j++){
            arr[i*j] = 1;
        }
    }
    int n=0;
    for(int i=2;;i++){
        if(!arr[i]){
            if(++n==K){
                cout << i;
                return 0;
            }
        }
    }
}