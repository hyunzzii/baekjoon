#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N,M;
int arr[8]={0,}, nrr[8]={0,};
string output;
void prt(int m){
    if(m == M){
        for(int i=0;i<M;i++){
            output += to_string(arr[i]) + ' ';
        }
        output += '\n';
        return ;
    }
    for(int i = 0; i<N; i++){
        arr[m] = nrr[i];
        prt(m+1);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> nrr[i];
    }
    sort(nrr, nrr+N);
    prt(0);
    cout << output;
}