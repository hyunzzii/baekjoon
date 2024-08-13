// #include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> node;

struct cmp{
    bool operator()(node &n1, node &n2){
        if(n1.first > n2.first){
            return true;
        }
        if(n1.first == n2.first && n1.second > n2.second){
            return true;
        }
        return false;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    priority_queue<node,vector<node>,cmp> queue;
    cin >> n;
    while(n--){
        cin >> x;
        if(!x){
            if(queue.empty()){
                cout << "0\n";
                continue;
            }
            cout << queue.top().second << '\n';
            queue.pop();
            continue;
        }
        node tem = make_pair(abs(x),x);
        queue.push(tem);
    }
}