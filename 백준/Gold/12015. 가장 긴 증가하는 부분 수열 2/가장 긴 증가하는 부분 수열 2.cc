#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr,result;

void change_result(int s, int e, int target){
    int mid;
    while(s<e){
        mid = (s+e)/2;
        if(result[mid] >= target){
            e = mid;
        }else{
            s = mid + 1;
        }
    }
    result[e] = target;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr = vector<int>(n);
    result = vector<int>(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int min = 1000001, len=0;
    result[0] = arr[0];
    for(int i=1;i<n;i++){
        if(result[len] < arr[i]){
            result[++len] = arr[i];
        }else{
            change_result(0,len,arr[i]);
        }
    }
    cout << len+1;
}