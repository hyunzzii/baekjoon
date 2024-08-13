#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(int n1, int n2){
        int abs_n1 = abs(n1);
        int abs_n2 = abs(n2);
        if(abs_n1 == abs_n2){
            return n1 > n2;
        }
        return abs(n1) > abs(n2);
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    priority_queue<int, vector<int>, cmp> queue;
    cin >> n;
    while(n--){
        cin >> x;
        if(!x){
            if(queue.empty()){
                cout << "0\n";
                continue;
            }
            cout << queue.top() << '\n';
            queue.pop();
            continue;
        }
        queue.push(x);
    }
}