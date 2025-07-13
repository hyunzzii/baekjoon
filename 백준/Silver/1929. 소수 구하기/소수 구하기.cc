#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m,n;
    cin >> m >> n;

    bool notPrime[1000001]={false};
    notPrime[1] = true;
    
    for(int i=2;i<=n;i++){
        for(int j=2;i*j<=n;j++){
            notPrime[i*j] = true;
        }
    }
    for(int i=m;i<=n;i++){
        if(notPrime[i]==false){
            cout << i << "\n";
        }
    }
}