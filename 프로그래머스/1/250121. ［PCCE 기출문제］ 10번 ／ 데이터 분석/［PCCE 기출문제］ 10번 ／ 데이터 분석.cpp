#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    vector<string> name = {"code", "date", "maximum", "remain"};
    int extNum, sortNum;
    for(int i=0;i<4;i++){
        if(!name[i].compare(ext))extNum = i;
        if(!name[i].compare(sort_by))sortNum = i;
    }
    for(vector<int> d : data){
        if(d[extNum] < val_ext) answer.push_back(d);
    }
    sort(answer.begin(), answer.end(), [sortNum](vector<int> a, vector<int> b){
        return a[sortNum] < b[sortNum];
    });
    return answer;
}