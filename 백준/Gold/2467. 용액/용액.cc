#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int compare(int a, int b){
    return abs(a) < abs(b);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,arr[100000]={0,},min=0,sum;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n,compare);

    for(int i=1;i<n-1;i++){
        if(abs(arr[i]+arr[i+1]) < abs(arr[min]+arr[min+1])){
            min = i;
        }
    }
    if(arr[min] < arr[min+1]){
        cout << arr[min] << " " << arr[min+1];
    }else{
        cout << arr[min+1] << " " << arr[min];
    }
}