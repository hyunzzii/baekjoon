#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    char str[101];
    while(true){ 
        cin.getline(str,101);
        if(str[0]=='.')break;

        char stack[101];
        int top=0, result = 1;

        for(int i=0;i<strlen(str);i++){
            char chr = str[i];
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