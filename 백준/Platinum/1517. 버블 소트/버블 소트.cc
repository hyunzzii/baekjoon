#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> tem;

long long int result = 0;

void merge_sort(int s, int e){
    int m = (e+s)/2;
    int s2 = m+1;

    if(s<m){
        merge_sort(s,m);
        merge_sort(s2,e);
        for(int i=s;i<=e;i++){
            tem[i] = v[i];
        }
    }

    int i=s;
    if(s>m || s2> e){
        v[s] = tem[s];
        return;
    }
    while(s<=m && s2<=e){
        if(tem[s] <= tem[s2]){
            v[i++] = tem[s++];
        }
        else{
            result += s2 - i;
            v[i++] = tem[s2++];
        }
    }
    while(s<=m){
        v[i++] = tem[s++];
    }
     while(s2<=e){
        v[i++] = tem[s2++];
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    v = vector<int>(n,0);
    tem = vector<int>(n,0);

    for(int i=0;i<n;i++){
        cin >> tem[i];
    }
    merge_sort(0,n-1);
    cout << result;
}