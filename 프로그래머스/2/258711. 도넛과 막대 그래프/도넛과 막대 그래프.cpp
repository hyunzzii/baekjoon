#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);
    vector<vector<int>> graph(1000001);
    vector<vector<int>> inout(1000001, vector<int>(2,0)); //(in, out)
    int num = 0;
    for(vector<int> e : edges){
        graph[e[0]].push_back(e[1]);
        inout[e[0]][1]++;
        inout[e[1]][0]++;
        if(e[0] > num)num = e[0];
        if(e[1] > num)num = e[1];
    }
    int productNum;
    for(int i=1;i<=num;i++){
        if(inout[i][0] == 0 && inout[i][1] >= 2){
            productNum = i;
            break;
        }
    }
    vector<bool> visited(num,false);
    for(int n : graph[productNum]){
        inout[n][0]--;
        int cur = n;
        answer[1]++;
        while(!visited[cur]){
            if(inout[cur][0] == 2 && inout[cur][1] == 2){
                answer[1]--;
                answer[3]++;
                break;
            }else if(!inout[cur][1]){
                answer[1]--;
                answer[2]++;
                break;
            }
            visited[cur] = true;
            for(int i : graph[cur]){
                if(!visited[i]) cur = i;
            }
        }
    }
    answer[0] = productNum;
    return answer;
}