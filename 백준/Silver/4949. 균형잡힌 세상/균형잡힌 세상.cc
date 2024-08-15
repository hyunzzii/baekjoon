#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string str;
    while(true){ 
        getline(cin,str);
        if(str.at(0)=='.')break;

        stack<int> stack;
        int result = 1;
        
        for(int i=0;i<str.length();i++){
            char chr = str.at(i);
            if(chr == '(' || chr == '['){
                stack.push(chr);
                continue;
            }
            if(chr == ')'){
                if(stack.empty() || stack.top() != '('){
                    result=0;
                    break;
                }
                stack.pop();
                continue;
            }
            if(chr == ']'){
                if(stack.empty() || stack.top() != '['){
                    result=0;
                    break;
                }
                stack.pop();
                continue;
            }
        }
        if(!stack.empty()){
            result=0;
        }
        cout << (result?"yes\n":"no\n");
    }
}