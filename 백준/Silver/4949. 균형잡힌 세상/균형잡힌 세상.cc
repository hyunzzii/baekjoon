#include <iostream>
#include <stack>
using namespace std;
typedef pair<int,int> node;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    while(true){ 
        getline(cin,str);
        if(str==".")break;

        stack<int> stack;
        string result[2] = {"yes","no"};
        int result_index = 0;
        
        for(int i=0;i<str.length();i++){
            char chr = str.at(i);
            if(chr == '(' || chr == '['){
                stack.push(chr);
                continue;
            }
            if(chr == ')'){
                if(stack.empty() || stack.top() != '('){
                    result_index=1;
                    break;
                }
                stack.pop();
                continue;
            }
            if(chr == ']'){
                if(stack.empty() || stack.top() != '['){
                    result_index=1;
                    break;
                }
                stack.pop();
                continue;
            }
        }
        if(!stack.empty()){
            result_index=1;
        }
        cout << result[result_index] << '\n';
    }
}