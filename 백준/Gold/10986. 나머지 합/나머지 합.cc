#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int N,M;
    long long int tem,sum=0;
    cin >> N >> M;
    
    int* arr = new int[N+1];
    long long int* mod = new long long int[M];

    fill_n(mod,M,0);
    arr[0] = 0;

    for(int i=1; i<N+1; i++){
        cin >> tem;
        tem = (arr[i-1] + (tem % M)) % M;
        arr[i] = tem;
        sum += mod[tem];
        mod[tem]++;
    }
    cout << sum + mod[0];
    delete[] arr;
}