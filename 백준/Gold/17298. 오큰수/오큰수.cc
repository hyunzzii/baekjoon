#include <iostream>
#include <stack>
using namespace std;
typedef pair<int,int> node;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tem;
    stack<node> stack;
    
    cin >> n;
    int result[n];
    
    for(int i=0;i<n;i++){
        cin >> tem;
        while(!stack.empty() && stack.top().first < tem){
            result[stack.top().second] = tem;
            stack.pop();
        }
        stack.push(make_pair(tem,i));
        result[i] = -1;
    }
    for(int i=0;i<n;i++){
        cout << result[i] << ' ';
    }
}