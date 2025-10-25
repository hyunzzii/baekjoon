#include <string>
#include <vector>
using namespace std;
typedef unsigned long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0, flag=0;
    int len = queue1.size();
    int s1=1, e1=len, s2=len+1, e2=len*2;
    ll sum1, sum2;
    vector<ll> board;
    board.push_back(0);
    while(s1<=e1 && s2<=e2){
        if(e2 >= board.size()){
            // for(int i=board.size()-1;i>=s1-1;i--)
            //     board[i] -= board[s1-1];
            for(int i: queue1)
                board.push_back(board[board.size()-1]+i);
            for(int i: queue2)
                board.push_back(board[board.size()-1]+i); 
        }
        sum1 = board[e1] - board[s1-1];
        sum2 = board[e2] - board[s2-1];
        if((sum1+sum2)%2)break;
        else if(sum1 == sum2){
            flag=1;
            break;
        }
        else if(sum1 > sum2){
            s1++;
            e2++;
        }else{
            s2++;
            e1++;
        }
        answer++;
        if(answer > len*10) break;
    }
    return flag ? answer : -1;
}