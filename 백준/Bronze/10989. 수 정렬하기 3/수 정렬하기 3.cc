#include <iostream>
// #include <cstdio>
// #include <stack>
#include <queue>
#include <vector>
// #include <algorithm>
// #include <utility>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,tem;
    int num[10001]={0,};

    cin >> n;
    while(n--){
        cin >> tem;
        num[tem]++;
    }

    for(int i=1;i<10001;i++){
        for(int j=0;j<num[i];j++){
            cout << i << "\n";
        }
    }
}