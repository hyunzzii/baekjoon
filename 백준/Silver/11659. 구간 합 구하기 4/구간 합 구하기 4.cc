#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    
    int* sum = new int[N+1];
    int* ptr = sum;
    int start, end, tem;

    *ptr++ = 0;
    while(N--){
        cin >> tem;
        *ptr = *(ptr-1) + tem;
        ptr++;
    }
    while(M--){
        cin >> start >> end;
        cout << sum[end] - sum[start-1] << "\n";
    }
    delete[] sum;
}