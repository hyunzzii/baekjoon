#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, tmp, sum=0;
    int stack[100001];
    int top = -1;
    cin >> K;
    while(K--){
        cin >> tmp;
        if(tmp){
            stack[++top] = tmp;
            sum += tmp;
        }else{
            sum -= stack[top--];
        }
    }
    cout << sum;
}