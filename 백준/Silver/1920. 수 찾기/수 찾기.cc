#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,v,m;
    cin >> n;
    
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end()); //오름차순

    cin >> m;
    while(m--){
        cin >> v;
        int s=0, e=n-1, flag=0;
        while(s<=e){
            int m = (s+e)/2;
            if(arr[m] == v){
                cout << "1\n";
                flag=1;
                break;
            }
            if(arr[m] > v){
                e = m - 1;
            }else{
                s = m + 1;
            }
        }
        if(!flag){
            cout <<"0\n";
        }
    }
} 