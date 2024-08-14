#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> node;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,tem;
    cin >> n;

    node arr[n];
    for(int i=0;i<n;i++){
        cin >> tem;
        arr[i] = make_pair(tem,i);
    }
    sort(arr,arr+n);
    int max=0;
    for(int i=0;i<n;i++){
        tem = arr[i].second - i;
        if(max < tem){
            max = tem;
        }
    }
    cout << max+1;
}