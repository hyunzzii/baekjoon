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

        char stack[100];
        int top=0, result = 1;

        for(int i=0;i<str.length();i++){
            char chr = str.at(i);
            if(chr == '(' || chr == '['){
                stack[top++] = chr;
                continue;
            }
            if(chr == ')'){
                if(!top|| stack[top-1] != '('){
                    result=0;
                    break;
                }
                top--;
                continue;
            }
            if(chr == ']'){
                if(!top|| stack[top-1] != '['){
                    result=0;
                    break;
                }
                top--;
                continue;
            }
        }
        if(top){
            result=0;
        }
        cout << (result?"yes\n":"no\n");
    }
}