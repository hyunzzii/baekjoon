#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,tem,num=0,good=0,start,end;
    cin >> N;

    vector<int> v(N,0);
    for(int i=0;i<N;i++){
        cin >> tem;
        v[i] = tem;
    }
    sort(v.begin(),v.end());
    
    while(num < v.size()){
        start = num==0 ? num+1 : 0;
        end = N-1==num ? num-1 : N-1;
        while(start<end){
            if(v[start] + v[end] == v[num]){
                good++;
                break;
            }
            else if(v[start] + v[end] < v[num]){
                start++;
                if(start==num)start++;
                continue;
            }
            end--;
            if(end==num)end--;
        }
        num++;
    }
    cout << good;
}