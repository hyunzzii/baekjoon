#include <iostream>
using namespace std;
#define min(a,b) (a<b)?a:b;
#define max(a,b) (a>b)?a:b;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,tem;
    cin >> n;

    int arr[2000001]={0,},base=1000000;
    int min = base, max = -base;

    for(int i=0;i<n;i++){
        cin >> tem;
        arr[base+tem] = 1;
        min = min(tem,min);
        max = max(tem,max);
    }

    for(int i=min;i<=max;i++){
        if(arr[i+base]){
            cout << i << '\n';
        }
    }
} 