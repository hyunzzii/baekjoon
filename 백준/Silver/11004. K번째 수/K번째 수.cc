#include <iostream>
#include <queue>
using namespace std;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k,tem;
    cin >> n >> k;

    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        cin >> tem;
        pq.push(tem);
    }
    while(n-->k){
        pq.pop();
    }
    cout << pq.top();
}