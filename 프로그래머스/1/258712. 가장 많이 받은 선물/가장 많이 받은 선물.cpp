#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int num = friends.size();
    int givtakes[51][51] = {0,}, giftScores[51] = {0,};
    int result[51] = {0,};
    // vector<vector<int>> givtakes(num, vector<int>(num,0));
    // vector<int> giftScores(num,0);
    for(string g : gifts){
        string aname = g.substr(0,g.find(" "));
        string bname = g.substr(g.find(" ")+1);
        int a,b;
        for(int i=0;i<num;i++){
            if(aname == friends[i]) a = i;
            if(bname == friends[i]) b = i;
        }
        givtakes[a][b]++;
        giftScores[a]++;
        giftScores[b]--;
    }
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            if(givtakes[i][j] == givtakes[j][i]){
                if(giftScores[i] > giftScores[j]) result[i]++;
                else if(giftScores[i] < giftScores[j]) result[j]++;
            }
            else if(givtakes[i][j] > givtakes[j][i])
                result[i]++;
            else
                result[j]++;
        }
    }
    for(int i=0;i<num;i++)
        if(answer < result[i]) answer = result[i];
    return answer;
}