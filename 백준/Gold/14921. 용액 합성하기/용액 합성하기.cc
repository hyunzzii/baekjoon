#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N;
int arr[100001] = {0,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    int left=0, right=N-1;
    int min = INT_MAX, tmp;
    while(left < right){
        tmp = arr[left] + arr[right];
        if(abs(tmp) < abs(min)) min = tmp;
        if(tmp > 0) right--;
        else if(tmp < 0) left++;
        else break; 
    }
    cout << min;
}