#include <string>
#include <vector>

using namespace std;

int h, w;
void move(vector<string> &park, vector<int> &cur, int dx, int dy, int num){
    int tx=cur[0], ty=cur[1];
    for(int i=0;i<num;i++){
        tx = tx + dx;
        ty = ty + dy;
        if(tx < 0 || tx >= h || ty >= w || ty < 0) return;
        if(park[tx][ty] == 'X')return;
    }
    cur[0] = tx;
    cur[1] = ty;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    h = park.size(), w = park[0].size();
    vector<int> cur(2,0);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(park[i][j]=='S'){
                cur[0] = i;
                cur[1] = j;
                break;
            }
        }
    }
    
    for(string r: routes){
        if(r[0] == 'N'){
           move(park, cur, -1, 0, r[2]-'0');
        }
        else if(r[0] == 'S'){
            move(park, cur, 1, 0, r[2]-'0');
        }
        else if(r[0] == 'W'){
            move(park, cur, 0, -1, r[2]-'0');
        }
        else if(r[0] == 'E'){
            move(park, cur, 0, 1, r[2]-'0');
        }
    }
    return cur;
}