#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,a,b,m,x,y;
    cin >> n;
    cin >> a >> b;
    cin >> m;

    vector<int> family(n+1,0);
    while(m--){
        cin >> x >> y;
        family[y] = x;
    }
    stack<int> s1,s2;
    s1.push(a);
    s2.push(b);
    while(true){
        a = family[a];
        if(a){
            s1.push(a);
        }
        else{
            break;
        }
    }
    while(true){
        b = family[b];
        if(b){
            s2.push(b);
        }
        else{
            break;
        }
    }
    if(s1.top() == s2.top()){
        do{
            s1.pop();
            s2.pop();
        }while(!s1.empty() && !s2.empty() && s1.top() == s2.top());
        cout << s1.size()+s2.size();
    }
    else{
        cout << -1;
    }
} 