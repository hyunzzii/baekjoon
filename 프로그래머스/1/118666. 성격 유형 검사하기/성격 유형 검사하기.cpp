#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    int scores[26] = {0,}, score;
    for(int i=0;i<choices.size();i++){
        score = choices[i] - 4;
        if(score)
            scores[survey[i][1] - 'A'] += score;
        else{
            scores[survey[i][0] - 'A'] -= score;
        }
    }
    string answer = "";
    if(scores['R'-'A'] < scores['T'-'A']) answer +="T";
    else answer +="R";
    
    if(scores['C'-'A'] < scores['F'-'A']) answer +="F";
    else answer +="C";
    
    if(scores['J'-'A'] < scores['M'-'A']) answer +="M";
    else answer +="J";
    
    if(scores['A'-'A'] < scores['N'-'A']) answer +="N";
    else answer +="A";
    
    return answer;
}