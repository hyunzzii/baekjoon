#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <stack>

using namespace std;

extern string submit(int);

stack<int> candidates;
vector<vector<int>> arr;
int nrr[4] = {0,0,0,0};
int nlen=0;
int notnum;

void addCan(int num, int n){
    if(n==4){
        candidates.push(num);
        return;
    }
    
    for(int i=0;i<arr[n].size();i++){
        int flag = 0;
        for(int j=0; j<n; j++){
            if(nrr[j] == arr[n][i]) flag = 1;
        }
        if(flag) continue;
        nrr[n] = arr[n][i];
        addCan(num + arr[n][i]*pow(10,3-n), n+1);
    } 
}

void check(){
    int cur = candidates.top();
    if(candidates.size()==3){
        int second = (cur%1000) / 100;
        int third = (cur%100) / 10;
        cur = cur - third*10 + second*10;
    }
    string r = submit(cur);
    nlen++;
    int strike = r[0] - '0';
    int ball = r[3] - '0';
    cout << cur <<" : "<<strike<<" , "<<ball<<"\n";
    stack<int> new_candidates;
    
    int tcur[4] = {cur / 1000, (cur%1000) / 100, (cur%100)/10, cur%10};
    while(!candidates.empty()){
        int c = candidates.top();
        candidates.pop();
        cout << c << "\n";
        int t_strike=0, t_ball=0;
        int tc[4] = {c / 1000, (c%1000) / 100, (c%100) / 10, c%10};
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(tc[i] == tcur[j]){
                    if(i == j) t_strike++;
                    else t_ball++;
                }
            }
        }
        if(t_strike == strike && t_ball == ball){
            new_candidates.push(c);
        }
    }
    cout<<"\n";
    candidates.swap(new_candidates);
}

int solution(int n) {
    int num = 0;
    arr = vector<vector<int>>(4, vector<int>(0)); 
    for(int i=1;i<=7;i+=2){
        if(num==4) break;
        string r = submit(i*1000 + i*100 + i*10 + i+1);
        nlen++;
        if(!r.compare("0S 4B")){
            for(int j=0;j<3;j++){
                arr[j].push_back(i+1);
            }
            arr[3].push_back(i);
            num+=2;
        }
        else if(!r.compare("0S 3B")){
            arr[3].push_back(i);
            num++;
            notnum = i+1;
        }
        else if(!r.compare("0S 1B")){
            for(int j=0;j<3;j++){
                arr[j].push_back(i+1);
            }
            num++;
            notnum = i;
        }
        else if(!r.compare("1S 3B")){
            for(int j=0;j<3;j++){
                arr[j].push_back(i);
                arr[j].push_back(i+1);
            }
            num+=2;
        }
        else if(!r.compare("1S 2B")){
            for(int j=0;j<3;j++){
                arr[j].push_back(i);
            }
            num++;
            notnum = i+1;
        }
        else if(!r.compare("1S 0B")){
            arr[3].push_back(i+1);
            num++;
            notnum = i;
        }
        else if(!r.compare("2S 2B")){
            for(int j=0;j<3;j++){
                arr[j].push_back(i);
            }
            arr[3].push_back(i+1);
            num+=2;
        }
    }
    if(num != 4){
        if(arr[0].size()==3){
            arr[3].push_back(9);
        }else{
            for(int j=0;j<3;j++){
                arr[j].push_back(9);
            }
        }
    }
    addCan(0,0);
    cout << "nlen : "<<nlen << "\n";
    while(candidates.size() > 1){
        check();
    }
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<arr[i].size();j++){
    //         cout << arr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout << "nlen : "<<nlen << "\n";
    // cout<<"\n";
    // while(!candidates.empty()){
    //     cout << candidates.top() << "\n";
    //     candidates.pop();
    // }

    return candidates.top();
}