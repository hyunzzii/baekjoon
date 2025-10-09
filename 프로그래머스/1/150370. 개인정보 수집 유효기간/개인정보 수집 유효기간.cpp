#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    //terms
    vector<int> t_terms = vector<int>(26,0);
    for(string term : terms){
        t_terms[term[0] - 'A'] = stoi(term.substr(2));
    }
    
    //logic
    int id = 1;
    for(string p : privacies){
        int term = p[11] - 'A';
        int expired_y, expired_m;
        expired_y = stoi(p.substr(0,4));
        expired_m = stoi(p.substr(5,2));
        string expired_d = p.substr(8,2);
        for(int i=1; i<=t_terms[term]; i++){
            expired_m++;
            if(expired_m > 12){
                expired_m = 1, expired_y++;
            }
        }
        string expired = "";
        expired += to_string(expired_y);
        expired += '.';
        if(expired_m < 10) expired += '0';
        expired += to_string(expired_m);
        expired += '.';
        expired += expired_d;
        cout << expired << "\n";
        if(today >= expired){
            answer.push_back(id);
        }
        id++;
    }
    return answer;
}