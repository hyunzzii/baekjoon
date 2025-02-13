#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,s,e,inp,mid;
    cin >> n;
    vector<int> arr(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    sort(arr.begin()+1,arr.end());

    cin >> m;
    while(m--){
        cin >> inp;
        s=1,e=n;
        while(s <= e){
            mid = (s+e)/2;
            if(inp > arr[mid]){
                s = mid+1;
            }else if(inp < arr[mid]){
                e = mid-1;
            }else{
                break;
            }
        }
        if(arr[mid]==inp){
            cout << "1 ";
        }else{
            cout << "0 ";
        }
    }
} 