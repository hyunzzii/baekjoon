#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num){
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
} 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> pn(n+1);

    pn[1].push_back(2);
    pn[1].push_back(3);
    pn[1].push_back(5);
    pn[1].push_back(7);

    int x[4]={1,3,7,9};

    for(int i=1;i<n;i++){
        for(int n : pn[i]){
            for(int j=0;j<4;j++){
                int tem = n*10+x[j];
                if(isPrime(tem)){
                    pn[i+1].push_back(tem);
                }
            }
        }
    }

    for(int n : pn[n]){
        cout << n <<"\n";
    }
}