#include <cstdio>
#include <vector>
using namespace std;

int arr[9][9], flag=0;
vector<pair<int,int>> ask;
int check_row[9][10] = {0,};
int check_col[9][10] = {0,};
int check_box[3][3][10] = {0,};

bool valid(int x, int y, int n){
    return !(check_row[x][n] || check_col[y][n] || check_box[x/3][y/3][n]);
}

void check(int i, int j){
    check_row[i][arr[i][j]] = 1;
    check_col[j][arr[i][j]] = 1;
    check_box[i/3][j/3][arr[i][j]] = 1;
}

void uncheck(int i, int j){
    check_row[i][arr[i][j]] = 0;
    check_col[j][arr[i][j]] = 0;
    check_box[i/3][j/3][arr[i][j]] = 0;
}

void func(int d){
    if(ask.size() == d){
        flag = 1;
        return;
    }
    int x = ask[d].first;
    int y = ask[d].second;
    for(int i=1;i<10;i++){
        if(!valid(x,y,i)) continue;
        arr[x][y] = i;
        check(x,y);
        func(d+1);
        if(flag) return;
        uncheck(x,y);
    }
    arr[x][y] = 0;
}

int main(void){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]){
                check(i,j);
                continue;
            }
            ask.push_back({i,j});
        }
    }
    func(0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}