#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int arr[9], sum = 0;
    for(int i=0;i<9;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    int i,j,flag=0;
    sort(arr, arr+9);
    for(i=0;i<9;i++){
        for(j=1;j<9;j++){
            if(sum - arr[i]-arr[j]==100){
                flag=1;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    for(int k=0;k<9;k++){
        if(k!=i && k!=j){
            cout << arr[k] << "\n";
        }
    }
}