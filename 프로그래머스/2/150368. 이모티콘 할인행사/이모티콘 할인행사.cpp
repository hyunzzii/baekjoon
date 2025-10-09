#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    int n = users.size(), m = emoticons.size();
    vector<int> answer = vector<int>(2,0);
    vector<vector<int>> arr = vector<vector<int>>(m, vector<int>(4));
    for(int i=0;i<m;i++){
        for(int f=1;f<5;f++){
            arr[i][f-1] = emoticons[i] - emoticons[i]*f*0.1;
        }
    }
    int dscnt[7] = {10,10,10,10,10,10,10};
    for(int i=0;i<pow(4,m);i++){
        long long sum = 0, num = 0, tmp[101] = {0,};
        for(int k=0;k<m;k++){
            for(int i=0;i<n;i++){
                if(users[i][0] <= dscnt[k]){
                    tmp[i] += arr[k][dscnt[k]/10 - 1];
                    sum += arr[k][dscnt[k]/10 - 1];
                }
            }
        }
        for(int i=0;i<n;i++){
            if(tmp[i] >= users[i][1]){
                sum -= tmp[i];
                num++;
            }
        }
        dscnt[m-1] += 10;
        for(int i=m-1; i>0; i--){
            if(dscnt[i] <= 40)break;
            dscnt[i] = 10;
            dscnt[i-1] += 10;
        }
        if(answer[0] < num){
            answer[0] = num;
            answer[1] = sum;
        }else if (answer[0] == num && answer[1] < sum){
            answer[1] = sum;
        }
    }
    return answer;
}

//할인율은 10, 20, 30, 40 중 하나
//가입자가 많은게 우선
//계산 총 4번이 최대 -> 브루트 포스...
//O(4^emoticons*users) = O(240100)