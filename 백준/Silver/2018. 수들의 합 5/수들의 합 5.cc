#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int N;
    long long int sum = 0;
    cin >> N;
    
    for(int i=1;;i+=2){
        if((N/i) - (i/2) < 1)break;
        if(N % i == 0){
            sum++;
        }
    }
    for(int i=2;; i+=2){
        if((N/i) - (i/2 - 1) < 1)break;
        if(N % i == i / 2){
            sum++;
        }
    }
    
    cout << sum;
}