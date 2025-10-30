#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}
bool compare(int a, int b){
    return a > b;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    int x = park.size(), y = park[0].size();
    for(int i=0; i<x; i++){
        for(int j=0;j<y;j++){
            if(park[i][j] == "-1"){
                int n = 1, flag = 1;
                answer = max(answer, n);
                while(i+n<x && j+n<y){
                    for(int k=0;k<=n;k++){
                        if(park[i+k][j+n] != "-1" || park[i+n][j+k] != "-1"){
                            flag = 0;
                            break;
                        }
                    }
                    if(!flag) break;
                    n++;
                }
                answer = max(answer, n);
            }
        }
    }
    sort(mats.begin(), mats.end(), compare);
    for(int m : mats){
        if(m <= answer){
            return m;
        }
    }
    return -1;
}