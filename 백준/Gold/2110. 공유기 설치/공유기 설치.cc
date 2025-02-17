#include <iostream>
#include <algorithm>
using namespace std;

int n,c;
unsigned arr[200000]={0,};

int find(int index, unsigned num){
    for(int i=index;i<n;i++){
        if(arr[i] >= num){
            return i;
        }
    }
    return -1;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);

    unsigned s=0,e=arr[n-1];
    while(s<=e){
        unsigned mid = (s+e)/2;
        int cnt=1;
        for(int i=0;i<n && cnt<c;cnt++){
            i = find(i,arr[i]+mid);
            if(i<0){
                break;
            }
        }
        if(cnt >= c){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    cout << e;
    //같을때 한칸 더 가는값(s,e)가 아닌 다른 값이 결과값
} 
