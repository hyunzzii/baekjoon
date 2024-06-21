#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, now, num=1, top=0, index=0;
    int stack[100001];
    char str[400001];
    
    cin >> n;
    while(n--){
        cin >> now;
        while(true){
            if(top && stack[top] == now){
                top--;
                str[index++]='-';
                str[index++]='\n';
                break;
            }
            if(top && stack[top] > now){
                cout << "NO";
                return 0;
            }
            stack[++top] = num++;
            str[index++]='+';
            str[index++]='\n';
        }
    }
    cout << str;
}