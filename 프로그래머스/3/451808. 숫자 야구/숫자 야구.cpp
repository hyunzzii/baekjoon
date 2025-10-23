#include <string>
#include <vector>
#include <queue>

using namespace std;

extern string submit(int);

bool check(int origin, int cur, int s, int b){
    int odiv[4] = {origin/1000, origin%1000/100, origin%100/10, origin%10};
    int cdiv[4] = {cur/1000, cur%1000/100, cur%100/10, cur%10};
    int ts=0, tb=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(odiv[i]==cdiv[j]){
                if(i==j)ts++;
                else tb++;
            }
        }
    }
    return ts==s && tb==b ? true : false;
}

int solution(int n) {
    queue<int> candidates;
    for(int i = 1234; i <= 9876; i++) {
        int idiv[4] = {i/1000, i%1000/100, i%100/10, i%10};
        int flag = 1;
        for(int j=0;j<4;j++){
            if(!idiv[j]){
                flag=0;
                break;
            }
            for(int k=j+1;k<4;k++){
                if(idiv[j]==idiv[k]) flag=0;
            }
        }
        if(flag) candidates.push(i);
    }
    
    while(candidates.size() > 1){
        int origin = candidates.front();
        string str = submit(origin);
        int s=str[0]-48, b=str[3]-48;
        int tmp = 0;
        while(true){
            int cur = candidates.front();
            if(cur == tmp) break;
            candidates.pop();
            if(check(origin, cur, s, b)){
                if(!tmp) tmp = cur;
                candidates.push(cur);
            }
        }
    }
    return candidates.front();
}