#include <iostream>
#include <deque>
using namespace std;

typedef pair<int,int> node;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,L,entry;
    cin >> N >> L;
    
    deque<node> deq;

    for(int i=1;i<=N;i++){
        cin >> entry;
        if(deq.size() && deq.front().first + L == i){
            deq.pop_front();
        }
        
        while(deq.size() && deq.back().second >= entry){
            deq.pop_back();
        }
        
        deq.push_back(make_pair(i,entry));
        cout << deq.front().second << ' ';
    }
}