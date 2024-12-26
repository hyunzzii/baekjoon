#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,p,q;
    int strawberry[100]={0,};
    int podo[100]={0,};
    int result[100]={0,};

    cin >> n >> p >> q;

    for(int i=0;i<n;i++){
        cin >> strawberry[i];
    }
    for(int i=0;i<n;i++){
        cin >> podo[i];
    }
    
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<10000;j++){
            if(strawberry[i]+j*p==podo[i]+j*q){
                result[i]=j;
                flag=1;
                break;
            }
        }
        if(!flag){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i=0;i<n;i++){
        cout << result[i] << " ";
    }
} 