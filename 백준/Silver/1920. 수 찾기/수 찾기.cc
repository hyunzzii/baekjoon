#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int tem,m;
    for(int i=0;i<n;i++){
        cin >> tem;
        arr.push_back(tem);
    }
    sort(arr.begin(),arr.end()); //오름차순

    cin >> m;
    while(m--){
        cin >> tem;
        cout << binary_search(arr.begin(),arr.end(),tem)<<"\n";
    }
} 