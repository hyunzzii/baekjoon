#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,N,M;
    cin >> T;

    while(T-- > 0){
        cin >> N >> M;

        int origin[N], prio[N];
        for(int i=0; i<N; i++){
            cin >> origin[i];
            prio[i] = -origin[i];
        }
        sort(prio,prio+N);
        int o=0, p=0, count=0;
        while(true){
            while(prio[p]!=-origin[o]){
                o = (o+1)%N;
            }
            origin[o] = 0;
            p++;

            count++;
            if(o==M)break;
        }
        cout << count;
        cout << '\n';
    }
}