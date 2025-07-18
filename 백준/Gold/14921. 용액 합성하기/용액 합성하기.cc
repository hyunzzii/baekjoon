#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N;
int arr[100001] = {0,};

int func(int s, int e, int target){
    int min = INT_MAX, mid, tmp;
    while(s <= e){
        mid = (s+e)/2;
        tmp = target +arr[mid];
        if(abs(tmp) < abs(min)){
            min = tmp;
        }
        if(!tmp) return 0;
        else if(tmp > 0) e = mid - 1;
        else s = mid + +1;
    }
    return min;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    int min = INT_MAX, tmp;
    for(int i=0;i<N-1;i++){
        tmp = func(i+1, N-1, arr[i]);
        if(abs(tmp) < abs(min)) min = tmp;
    }
    cout << min;
}