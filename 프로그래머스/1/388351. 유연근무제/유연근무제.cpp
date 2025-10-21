#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = schedules.size();
    int start;
    for(int i=0;i<schedules.size();i++){
        schedules[i] = schedules[i] + 10;
        if(schedules[i] % 100 > 59){
            schedules[i] = schedules[i] - 60 + 100;
        }
        start = startday;
        for(int j=0;j<timelogs[i].size();j++,start++){
            if(start >= 6){
                start = start % 7;
                continue;
            }
            if(schedules[i] < timelogs[i][j]){
                answer--;
                break;
            }
        }
    }
    return answer;
}