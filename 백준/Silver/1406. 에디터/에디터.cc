#include <iostream>
#include <stack>
using namespace std;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    stack<char> stack;
    int t;

    cin >> t;
    while(t--){
        char c;
        cin >> c; //cin은 공백 빼고 입력받음
        if(c=='L'){
            if(!str.empty()){
                stack.push(str.back());
                str.pop_back();
            }
        }
        else if(c=='D'){
            if(!stack.empty()){
                str.push_back(stack.top());
                stack.pop();
            }
        }
        else if(c=='B'){
            if(!str.empty()){
                str.pop_back();
            }
        }
        else {
            cin >> c;
            str.push_back(c);
        }
    }
    for(char c : str){
        cout << c;
    }
    while(!stack.empty()){
        cout << stack.top();
        stack.pop();
    }
}