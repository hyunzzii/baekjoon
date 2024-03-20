#include <iostream>
#include <string>

using namespace std;

int stoi(char c){
    if(c=='A') return 0;
    if(c=='C') return 1;
    if(c=='G') return 2;
    return 3;
}
int func(int* main, int* sub){
    for(int i=0;i<4;i++){
        if(sub[i]<main[i]) return 0;
    }
    return 1;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S,P,sum=0,cond[4];
    string str;

    cin >> S >> P;
    cin >> str;

    for(int i=0;i<4;i++){
        cin >> cond[i];
    }

    int sub[4] = {0,};
    for(int i=0;i<P;i++){
        sub[stoi(str[i])]++;
    }
    
    sum += func(cond,sub);
    for(int i=0;i+P<S;i++){
        sub[stoi(str[i])]--;
        sub[stoi(str[i+P])]++;
        sum += func(cond,sub);
    }
    cout << sum;
}