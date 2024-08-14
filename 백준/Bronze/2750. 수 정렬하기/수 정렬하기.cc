// #include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[n],tem;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        int flag = 1;
        for(int j=1;j<n-i;j++){
            if(arr[j-1]>arr[j]){
                tem = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tem;
                flag = 0;
            }
        }
        if(flag) break;
    }
    
    for(int i=0;i<n;i++){
        cout << arr[i] <<'\n';
    }
}