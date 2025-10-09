#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int d = n-1, p = n-1, tmp, td, tp;
    while(deliveries[d]==0) d--;
    while(pickups[p]==0)p--;
    while(true){
        int d_cap = cap, p_cap = cap;
        td = d < 0 ? -1 : d, tp = p < 0 ? -1 : p;
        while(d_cap>=0 && d >= 0){
            tmp = d_cap;
            d_cap -= deliveries[d];
            if(d_cap >= 0) deliveries[d--] = 0;
            else deliveries[d] -= tmp;
        }
        while(p_cap>=0 && p >= 0){
            tmp = p_cap;
            p_cap -= pickups[p];
            if(p_cap >= 0) pickups[p--] = 0;
            else pickups[p] -= tmp;
        }
        
        answer += (max(td, tp)+1) * 2;
        if(d<0 && p<0) break;
    }
    return answer;
}