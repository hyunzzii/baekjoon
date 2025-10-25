#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    int num = 0;
    for(vector<int> e : edges){
        if(e[0] > num)num = e[0];
        if(e[1] > num)num = e[1];
    }
    vector<int> in(num+1,0), out(num+1,0);
    for(vector<int> e : edges){
        in[e[1]]++;
        out[e[0]]++;
    }
    int productNum, circle, bar=0, eight=0;
    for(int i=1;i<=num;i++){
        if(!in[i] && out[i] >= 2){
            productNum = i;
            break;
        }
    }
    circle = out[productNum];
    for(int i=1;i<=num;i++){
        if(i==productNum)continue;
        if(out[i] == 2){
            circle--;
            eight++;
        }
        else if(in[i] && out[i] == 0){
            circle--;
            bar++;
        }
    }
    return {productNum, circle, bar, eight};
}