#include <iostream>
#include <vector>
using namespace std;

int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}
vector<vector<int> > func(int* arr,vector<vector<int> > v,int x, int y){
    int dx[8] = {0,0,1,-1,-1,-1,1,1};
    int dy[8] = {1,-1,0,0,1,-1,1,-1};

    for(int i=0;i<8;i++){
        int _x = x+dx[i];
        int _y = y+dy[i];
        if(v[_x][_y] > 0){
            if(v[_x][_y] > 1){
                arr[v[_x][_y]] = min(arr[v[_x][_y]],arr[v[x][y]]);
                arr[v[x][y]] = min(arr[v[_x][_y]],arr[v[x][y]]);
            }
            v[_x][_y] = arr[v[x][y]];
        }
    }
    return v;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w,h;
    while(true){
        int num=2,sum=0;
        cin >> w >> h;
        if(w==0)break;

        int arr[1000] ={0,};
        vector<vector<int> > v(h+2, vector<int>(w+2,0));
        
        for(int i=1;i<h+1;i++){
            for(int j=1;j<w+1;j++){
                cin >> v[i][j];
            }
        }

        for(int i=1;i<h+1;i++){
            for(int j=1;j<w+1;j++){
                if(v[i][j] > 0){
                    if(v[i][j]==1){
                        arr[num] = num;
                        v[i][j] = num++;
                    }
                    v = func(arr,v,i,j);
                }
            }
        }
        for(int i=2;i<num;i++){
            if(arr[i]==i){
                sum++;
            }
        }
        cout << sum <<"\n";
    }
}