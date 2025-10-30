#include <string>
#include <vector>

using namespace std;
int min(int a, int b){
    return a < b ? a : b;
}

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int htime = bandage[0], heal = bandage[1], plusheal = bandage[2];
    int attackIdx = 0, seq = 0, cur=health;
    for(int i=1; attackIdx<attacks.size(); i++){
        if(i < attacks[attackIdx][0]){
            if(++seq == htime){
                cur += plusheal;
                seq = 0;
            }
            cur = min(health, cur+heal);
        }else{
            cur -= attacks[attackIdx][1];
            attackIdx++;
            seq=0;
        }
        if(cur <= 0)return -1;
    }
    return cur;
}