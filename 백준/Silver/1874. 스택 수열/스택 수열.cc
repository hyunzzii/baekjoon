#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, now, num=1;
    stack<int> s;
    cin >> n;
    
    vector<string> result;
    while(n--){
        cin >> now;
        while(true){
            if(s.size() && s.top() == now){
                s.pop();
                result.push_back("-");
                break;
            }
            if(s.size() && s.top() > now){
                cout << "NO";
                return 0;
            }
            s.push(num++);
            result.push_back("+");
        }
    }
    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }
}