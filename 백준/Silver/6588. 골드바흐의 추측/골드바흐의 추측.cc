#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    const int max =1000000;
    bool notPrime[max+1] = {false};
    for(int i=2;i<max;i++){
        for(int j=2;i*j<=max;j++){
            notPrime[i*j] = true;
        }
    }
    while(true){
        int input, a = 0;
        cin >> input;
        if(input==0) break;
        for(int i=3; i<=input/2; i+=2){
            if(!notPrime[i] && !notPrime[input-i]){
                a = i;
                break;
            }
        }
        if(!a){
            cout << "Goldbach's conjecture is wrong.\n";
            break;
        }
        cout << input << " = " << a << " + "<< input-a <<"\n";
    }
}