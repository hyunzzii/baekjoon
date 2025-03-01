#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    int tem;
    cin >> N >> M;
    
    int** arr = new int*[N+1];
    for(int i=0; i<N+1; i++){
        arr[i] = new int[N];
        memset(arr[i],0,sizeof(int)*N);
    }
    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            cin >> tem;
            arr[i][j] = tem + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    int x1,y1,x2,y2;
    while(M--){
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cout << arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1] << "\n";
    }

    for(int i=0; i<N; i++) delete[] arr[i];
    delete[] arr;
}