#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int num = id_list.size();
    vector<int> answer(num, 0);
    vector<vector<int>> red(num, vector<int>(num,0));
    int sum[1001] = {0,};
    for(string r : report){
        string user = r.substr(0,r.find(" "));
        string redUser = r.substr(r.find(" ")+1);
        int uId, rId;
        for(int i=0;i<num;i++){
            if(!user.compare(id_list[i])) uId = i;
            if(!redUser.compare(id_list[i])) rId = i;
        }
        if(!red[rId][uId]){
            red[rId][uId] = 1;
            sum[rId]++;
        }
    }
    for(int i=0;i<num;i++){
        if(sum[i] < k) continue;
        for(int j=0;j<num;j++){
            if(red[i][j]) answer[j]++;
        }
    }
    return answer;
}